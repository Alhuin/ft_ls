/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:10:55 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/18 14:27:11 by jjanin-r    ###    #+. /#+    ###.fr     */
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
	if (S_ISLNK(mode))
		ft_strcat(ret, "l");
	else if (S_ISCHR(mode))
		ft_strcat(ret, "c");
	else if (S_ISBLK(mode))
		ft_strcat(ret, "b");
	else if (S_ISFIFO(mode))
		ft_strcat(ret, "p");
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
	int (*ascii)(t_file*, t_file*);
	int (*rascii)(t_file*, t_file*);
	int (*time)(t_file*, t_file*);
	int (*rtime)(t_file*, t_file*);
	int (*err)(t_file*, t_file*);

	ascii = ascii_sort;
	rascii = rev_ascii_sort;
	time = time_sort;
	rtime = rev_time_sort;
	err = err_sort;
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

	if (flags->bigr == 1)
		flags->arg++;
	rep = opendir(path);
	if (rep == NULL)
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
	if (flags->bigr == 1 && flags->arg > 2)
		ft_printf("%s:\n", (flags->bigr == 1 ? (*file)->path : (*file)->name));
	if (flags->l == 1 && flags->un != 1)
		ft_printf("total %d\n", (*file)->total);
	ft_print_tree((*file)->subtree, flags);
	ft_printf(flags->arg > 2 ? "\n\n" : "\n");
	if ((*file)->arg == 1 && (*file)->subtree && flags->bigr == 1)
		ft_recursive((*file)->subtree, &flags);
	return (0);
}
