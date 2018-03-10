/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:10:55 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 15:46:11 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_perms(mode_t mode)
{
	char	*ret;

	if (!(ret = malloc(sizeof(char) * 11)))
		return (NULL);
	ret[0] = '\0';
	if (S_ISLNK(mode))
		ft_strcat(ret, "l");
	else
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

char	*ft_buildpath(char *arg, char *name)
{
	int		i;
	int		slash;
	char	*ret;
	char	*tmp = NULL;

	slash = 0;
	i = 0;
	if (arg)
	{
		if (arg[0] == '/')
			return (arg);
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
		tmp = ret;
		ret = ft_strjoin(ret, name);
		ft_strdel(&tmp);
	}
	return (ret);
}

int		ft_fill_tree(t_file **file, t_tree **tree, t_flags *flags, int error)
{
	int (*ascii)(t_file*, t_file*) = ascii_sort;
	int (*rascii)(t_file*, t_file*) = rev_ascii_sort;
	int (*time)(t_file*, t_file*) = time_sort;
	int (*rtime)(t_file*, t_file*) = rev_time_sort;
	int (*err)(t_file*, t_file*) = err_sort;

	if (error == 1)
		ft_double_sort(file, tree, err, ascii);
	else if (flags->t == 1 && flags->r != 1)
		ft_double_sort(file, tree, time, ascii);
	else if (flags->t == 1 && flags->r == 1)
		ft_double_sort(file, tree, rtime, rascii);
	else if (flags->r == 1 && flags->t != 1)
		ft_sort(file, tree, rascii);
	else
		ft_sort(file, tree, ascii);
	return (0);
}

int		ft_subfile_init(t_file **subfile, int lengh, char *path, char *name)
{
	if (!(*subfile = malloc(sizeof(t_file))))
		return (-1);
	(*subfile)->total = 0;
	(*subfile)->name = ft_strdup(name);
	if ((int)ft_strlen((*subfile)->name) > lengh)
		lengh = (int)ft_strlen((*subfile)->name);
	(*subfile)->path = ft_buildpath(path, (*subfile)->name);
	lstat((*subfile)->path, &(*subfile)->sb);
	if (lengh < (int)ft_strlen((*subfile)->name))
		lengh = (int)ft_strlen((*subfile)->name);

	return (0);
}

int		ft_getdirstats(t_file **file, char *path, t_flags *flags)
{
	DIR				*rep;
	struct dirent	*fichierlu;
	int				lengh;
	t_file			*subfile;

	lengh = 0;
	rep = opendir(path);
	if (rep == NULL)
	{
		(*file)->error = ft_strdup(strerror(errno));
		ft_printf("ft_ls: %s: %s\n", (*file)->name, (*file)->error);
		ft_strdel(&(*file)->error);
		return (-1);
	}
	while ((fichierlu = readdir(rep)) != NULL)
	{
		ft_subfile_init(&subfile, lengh, path, fichierlu->d_name);
		if (flags->l == 1)
			(*file)->total += subfile->sb.st_blocks;
		ft_fill_tree(&subfile, &(*file)->subtree, flags, 0);
	}
	if (rep == NULL || closedir(rep) == -1)
	{
		(*file)->error = ft_strdup(strerror(errno));
		ft_printf("ft_ls: %s: %s\n", (*file)->name, (*file)->error);
		ft_strdel(&(*file)->error);
		return (-1);
	}
	ft_printf("%s:\n", (flags->bigr == 1 ? (*file)->path : (*file)->name));
	if (flags->l == 1)
		ft_printf("total %d\n", (*file)->total);
	ft_print_tree((*file)->subtree, lengh + 1, flags);
	ft_printf(flags->l == 1 ? "\n" : "\n\n");
	return (0);
}
