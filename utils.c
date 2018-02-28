/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:10:55 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 21:17:11 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoinfree(char *s1, char *s2, int f)
{
	char	*ret;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[i])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	if (f == 1 || f == 3)
		ft_strdel(&s1);
	if (f == 2 || f == 3)
		ft_strdel(&s2);
	return (ret);
}

char	*ft_get_perms(mode_t mode)
{
	char	*ret;

	if (!(ret = malloc(sizeof(char) * 11)))
		return (NULL);
	ret[0] = '\0';
	if (S_ISLNK(mode))
		ft_strcat(ret, "l");
	else if (S_ISDIR(mode))
		ft_strcat(ret, "d");
	else
		ft_strcat(ret, "-");
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
		ret = ft_strjoinfree(arg, name, 0);
	else
	{
		ret = ft_strjoin((arg ? arg : "."), "/");
		ret = ft_strjoinfree(ret, name, 0);
	}
	return (ret);
}

int		ft_fill_tree(t_file **file, t_tree **tree, t_flags *flags)
{
	if (flags->t == 1 && flags->r != 1)
		ft_taddnode(file, tree);
	else if (flags->t == 1 && flags->r == 1)
		ft_traddnode(file, tree);
	else if (flags->r == 1 && flags->t != 1)
		ft_raddnode(file, tree);
	else
		ft_addnode(file, tree);
	return (0);
}

int		ft_subfile_init(t_file **subfile, int lengh, char *path, char *name)
{
	if (!(*subfile = malloc(sizeof(t_file))))
		return (-1);
	(*subfile)->name = ft_strdup(name);
	if ((int)ft_strlen((*subfile)->name) > lengh)
		lengh = ft_strlen((*subfile)->name);
	(*subfile)->path = ft_buildpath(path, (*subfile)->name);
	lstat((*subfile)->path, &(*subfile)->sb);
	return (0);
}

int		ft_getdirstats(t_file **file, char *path, t_flags *flags)
{
	DIR				*rep;
	struct dirent	*fichierlu;
	int				lengh;
	t_file			*subfile = NULL;

	lengh = 0;
	rep = opendir(path);
	if (rep == NULL)
		exit(-1);
	while ((fichierlu = readdir(rep)) != NULL)
	{
		ft_subfile_init(&subfile, lengh, path, fichierlu->d_name);
		if (lengh < (int)ft_strlen(subfile->name))
			lengh = (int)ft_strlen(subfile->name);
		if (flags->l == 1)
			(*file)->total += subfile->sb.st_blocks;
		ft_fill_tree(&subfile, &(*file)->subtree, flags);
	}
	if (closedir(rep) == -1)
		exit(-1);
	if (flags->arg > 1)
		ft_printf("%s:\n", (*file)->name);
	if (flags->l == 1)
		ft_printf("total %d\n", (*file)->total);
	ft_print_tree((*file)->subtree, lengh + 1, flags);
	ft_free_tree(&(*file)->subtree);
	if (flags->arg > 0)
		ft_printf("\n");
	return (0);
}

int			ft_free_node(t_tree **node)
{
	(*node)->left = NULL;
	(*node)->right = NULL;
	ft_strdel(&(*node)->file->name);
	ft_strdel(&(*node)->file->path);
	free((*node)->file);
	free(*node);
	*node = NULL;
	return (0);
}

int			ft_free_tree(t_tree **tree)
{
	if ((*tree)->left)
		return (ft_free_tree(&(*tree)->left));
	if ((*tree)->right)
		return (ft_free_tree(&(*tree)->right));
	if ((*tree)->file->subtree)
		ft_free_tree(&(*tree)->file->subtree);
	if ((*tree)->file->alphatime)
		ft_free_tree(&(*tree)->file->alphatime);
	ft_free_node(tree);
	return (0);
}
