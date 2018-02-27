/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:17:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 18:58:05 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_date(char *time, char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'M')
			ft_printf("%4.3s", time + 4);
		if (str[i] == 'D')
			ft_printf("%3.2s", time + 8);
		if (str[i] == 'H')
			ft_printf("%6.5s", time + 11);
		i++;
	}
}

char	*ft_get_perms(mode_t mode)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * 11)))
		return (NULL);
	ret[0] = '\0';
	ft_strcat(ret, (S_ISDIR(mode) ? "d" : "-"));
	ft_strcat(ret, ((mode & S_IRUSR) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWUSR) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXUSR) ? "x" : "-"));
	ft_strcat(ret, ((mode & S_IRGRP) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWGRP) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXGRP) ? "x" : "-"));
	ft_strcat(ret, ((mode & S_IROTH) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWOTH) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXOTH) ? "x" : "-"));
	return (ret);
}


int		ft_printl(t_file **file, t_flags **flags)
{
	struct group *grp;
	struct passwd *pwd;
	char *time;

	if ((*file)->name[0] != '.' || (*flags)->a == 1)
	{
		ft_printf("%s", ft_get_perms((*file)->sb.st_mode));
		ft_printf("%4ld", (*file)->sb.st_nlink);
		grp = getgrgid((*file)->sb.st_gid);
		pwd = getpwuid((*file)->sb.st_uid);
		ft_printf("%9s", pwd->pw_name);
		ft_printf("%9s", grp->gr_name);
		ft_printf("%8lld", (*file)->sb.st_size);
		time = ctime(&(*file)->sb.st_mtime);
		ft_print_date(time, "MDH");
		if (S_ISDIR((*file)->sb.st_mode))
			ft_printf(" {bcyan}%s{eoc}\n", (*file)->name);
		else if ((*file)->sb.st_mode & S_IXUSR)
			ft_printf(" {red}%s{eoc}\n", (*file)->name);
		else
			ft_printf(" %s\n", (*file)->name);
	}
	return (0);
}

char		*ft_buildpath(char *arg, char *name)
{
	int i;
	int slash;
	char *ret;

	slash = 0;
	i = 0;
	if (arg)
	{
		while (arg[i])
			i++;
		i--;
		slash = (arg[i] == '/' ? 1 : 0);
	}
	if (arg && slash == 1)
		ret = ft_strjoin(arg, name);
	else
	{
		ret = ft_strjoin((arg ? arg : "."), "/");
		ret = ft_strjoin(ret, name);
	}
	return (ret);
}

static int		ft_getflags(t_flags **flags, char *arg)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	if (arg[i++] == '-')
	{
		if (arg[i] == '-')
			return (-1);
		ret = 1;
		while (arg[i])
		{
			if (arg[i] == 'l')
				(*flags)->l = 1;
			else if (arg[i] == 'a')
				(*flags)->a = 1;
			else if (arg[i] == 'r')
				(*flags)->r = 1;
			else if (arg[i] == 'R')
				(*flags)->R = 1;
			else if (arg[i] == 't')
				(*flags)->t = 1;
			else
				return (-1);
			i++;
		}
	}
	return (ret);
}

int		ft_getdirstats(t_file **file, char *path, t_flags *flags)
{
	DIR* rep = NULL;
	struct dirent *fichierLu = NULL;
	int lengh = 0;
	t_file *subfile;

	rep = opendir(path);
	if (rep == NULL)
		exit(-1);
	while ((fichierLu = readdir(rep)) != NULL)
	{
		if (!(subfile = malloc(sizeof(t_file))))
			return (-1);
		subfile->name = ft_strdup(fichierLu->d_name);
		if ((int)ft_strlen(subfile->name) > lengh)
			lengh = ft_strlen(subfile->name);
		subfile->path = ft_buildpath(path, subfile->name);
		stat(subfile->path, &subfile->sb);
		if (flags->l == 1)
			(*file)->total += subfile->sb.st_blocks;
		if (flags->t == 1 && flags->r != 1)
			ft_taddnode(&subfile, &(*file)->subtree);
		else if (flags->t == 1 && flags->r == 1)
			ft_traddnode(&subfile, &(*file)->subtree);
		else if (flags->r == 1 && flags->t != 1)
			ft_raddnode(&subfile, &(*file)->subtree);
		else
			ft_addnode(&subfile, &(*file)->subtree);
	}
	if (closedir(rep) == -1)
		exit(-1);
	ft_printf("%s:\n", (*file)->name);
	if (flags->l == 1)
		ft_printf("total %d\n", (*file)->total);
	ft_print_tree((*file)->subtree, lengh + 1, flags);
	ft_printf(flags->l == 1 ? "\n" : "\n\n");
	return (0);
}

int		ft_getargs(t_file **file, char *arg, char *pref, int a)
{
	(*file)->arg = a;
	(*file)->path = ft_strjoin((pref ? pref :"./" ), arg);
	if (!((*file)->name = ft_strdup(arg)))
		return (-1);
	stat((*file)->path, &(*file)->sb);
	return (0);
}

int main(int argc, char *argv[])
{
	t_flags		*flags;
	t_tree		*tree = NULL;
	t_file		*file;
	int			i;

	i = 1;
	if (!(flags = malloc(sizeof(t_flags))))
		return (-1);
	while (ft_getflags(&flags, argv[i]) == 1)
		i++;
	while (i < argc)
	{
		if (!(file = malloc(sizeof(t_file))))
			return (-1);
		file->total = 0;
		file->subtree = NULL;
		file->alphatime = NULL;
		ft_getargs(&file, argv[i], NULL, 1);
		if (flags->t == 1 && flags->r != 1)
			ft_taddnode(&file, &tree);
		else if (flags->t == 1 && flags->r == 1)
			ft_traddnode(&file, &tree);
		else if (flags->r == 1 && flags->t != 1)
			ft_raddnode(&file, &tree);
		else
			ft_addnode(&file, &tree);
		i++;
	}
	ft_computeargs(tree, &flags);
	return (0);
}
