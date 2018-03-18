/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:10:55 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/18 16:34:26 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_ls.h"

char	*ft_get_perms(mode_t mode)
{
	char	*ret;

	if (!(ret = malloc(sizeof(char) * 11)))
		return (NULL);
	ret[0] = '\0';
	ret = ft_firstperm(ret, mode);
	ft_strcat(ret, ((mode & S_IRUSR) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWUSR) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXUSR) ? "x" : "-"));
	ft_strcat(ret, ((mode & S_IRGRP) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWGRP) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXGRP) ? "x" : "-"));
	ft_strcat(ret, ((mode & S_IROTH) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWOTH) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXOTH) ? "x" : "-"));
	if (mode & S_ISVTX)
		ft_strcat(ret, ((mode & S_IXUSR) ? "t" : "T"));
	return (ret);
}

char	*ft_buildpath(char *arg, char *name)
{
	int		i;
	int		slash;
	char	*ret;
	char	*tmp;

	tmp = NULL;
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
		tmp = ret;
		ret = ft_strjoin(ret, name);
		ft_strdel(&tmp);
	}
	return (ret);
}

int		ft_fill_tree(t_file **file, t_tree **tree, t_flags *flags, int error)
{
	void *f[6];

	f[0] = &ascii_sort;
	f[1] = &rev_ascii_sort;
	f[2] = &mtime_sort;
	f[3] = &atime_sort;
	f[4] = &rev_time_sort;
	f[5] = &err_sort;
	if (error == 1)
		ft_double_sort(file, tree, f[5], f[0]);
	else if (flags->f == 1)
		ft_addnode(file, tree);
	else if (flags->t == 1 && flags->r != 1 && flags->u == 1)
		ft_double_sort(file, tree, f[3], f[0]);
	else if (flags->t == 1 && flags->r != 1)
		ft_double_sort(file, tree, f[2], f[0]);
	else if (flags->t == 1 && flags->r == 1)
		ft_double_sort(file, tree, f[4], f[1]);
	else if (flags->r == 1 && flags->t != 1)
		ft_sort(file, tree, f[1]);
	else
		ft_sort(file, tree, f[0]);
	return (0);
}

int		ft_subfile_init(t_file **subfile, char *path, char *name)
{
	if (!(*subfile = malloc(sizeof(t_file))))
		return (-1);
	(*subfile)->total = 0;
	(*subfile)->name = ft_strdup(name);
	(*subfile)->path = ft_buildpath(path, (*subfile)->name);
	lstat((*subfile)->path, &(*subfile)->sb);
	return (0);
}

int		ft_getdirstats(t_file **file, char *path, t_flags *flags)
{
	DIR				*rep;
	struct dirent	*fichierlu;
	t_file			*subfile;

	flags->arg++;
	if ((rep = opendir(path)) == NULL)
		return (ft_error(*file, strerror(errno), flags));
	while ((fichierlu = readdir(rep)) != NULL)
	{
		ft_subfile_init(&subfile, path, fichierlu->d_name);
		if (flags->l == 1 && (subfile->name[0] != '.' || flags->a == 1))
			(*file)->total += subfile->sb.st_blocks;
		ft_fill_tree(&subfile, &(*file)->subtree, flags, 0);
	}
	if (rep == NULL || closedir(rep) == -1)
		return (ft_error(*file, strerror(errno), flags));
	if (flags->arg > 2)
		ft_printf("%s:\n", (flags->bigr == 1 ? (*file)->path : (*file)->name));
	if (flags->l == 1 && flags->un != 1)
		ft_printf("total %d\n", (*file)->total);
	ft_print_tree((*file)->subtree, flags);
	ft_printf(flags->arg > 2 ? "\n\n" : "\n");
	if ((*file)->arg == 1 && (*file)->subtree && flags->bigr == 1)
		ft_recursive((*file)->subtree, &flags);
	return (0);
}
