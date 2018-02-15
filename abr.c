/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   abr.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:11 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 23:28:05 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_permissions(mode_t mode, t_arbre **arbre)
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
	if (ret[0] == 'd')
		(*arbre)->file->dir = 1;
	else if (ret[3] == 'x' || ret[6] == 'x' || ret[9] == 'x')
		(*arbre)->file->exec = 1;
	return (ret);
}

int		ft_get_stats(char *name, t_arbre **arbre, char *path)
{
	(*arbre)->file = malloc(sizeof(t_file));
	(*arbre)->file->sb = malloc(sizeof(struct stat));
	stat(path, (*arbre)->file->sb);
	if (name[0] == '.')
		((*arbre)->file->hidden = 1);
	(*arbre)->file->permissions =
		ft_get_permissions((*arbre)->file->sb->st_mode, arbre);
	return (0);
}

int				ft_createnode(char *name, t_arbre **tocreate, char *path)
{
	t_arbre *node;
	if (!(node = malloc(sizeof(t_arbre))))
		return (-1);
	if (!(node->name = ft_strdup(name)))
		return (-1);
	if (!(node->file = malloc(sizeof(t_file))))
		return (-1);
	ft_get_stats(name, &node, path);
	node->left = NULL;
	node->right = NULL;
	*tocreate = node;
	return (0);
}

int				ft_addnode(char *name, t_arbre **node, char *path)
{
	if (*node == NULL)
		return (ft_createnode(name, node, path));
	else
	{
		if (ft_strcmp(name, (*node)->name) > 0)
		{
			if ((*node)->right)
				ft_addnode(name, &(*node)->right, path);
			else
				return (ft_createnode(name, &(*node)->right, path));
		}
		if (ft_strcmp(name, (*node)->name) < 0)
		{
			if ((*node)->left)
				ft_addnode(name, &(*node)->left, path);
			else
				return (ft_createnode(name, &(*node)->left, path));
		}
	}
	return (0);
}

void			ft_print_name(t_arbre *arbre, int type, int lengh)
{
	if (type != 1 && arbre->file->hidden != 1)
	{
		if (arbre->file->dir == 1)
			ft_printf("{bcyan}%-*s{eoc}", lengh, arbre->name);
		else if (arbre->file->exec == 1)
			ft_printf("{red}%-*s{eoc}", lengh, arbre->name);
		else
			ft_printf("%-*s", lengh, arbre->name);
	}
}

void			ft_print_tree(t_arbre *arbre, int type, int lengh)
{
	if (arbre != NULL)
	{
		if (arbre->left)
			ft_print_tree(arbre->left, type, lengh);
		ft_print_name(arbre, type, lengh);
		if (arbre->right)
			ft_print_tree(arbre->right, type, lengh);
	}
}

void			ft_rev_print_tree(t_arbre *arbre, int type, int lengh)
{
	if (arbre != NULL)
	{
		if (arbre->right)
			ft_rev_print_tree(arbre->right, type, lengh);
		ft_print_name(arbre, type, lengh);
		if (arbre->left)
			ft_rev_print_tree(arbre->left, type, lengh);
	}
}
/*
   int main()
   {
   t_arbre *arbre = NULL;
   ft_addnode("Bonjour", &arbre);
   ft_addnode("Je", &arbre);
   ft_addnode("appelle", &arbre);
   ft_addnode("Monsieur", &arbre);
   ft_addnode("Marche", &arbre);
   ft_addnode("PUTAIN", &arbre);
   ft_print_tree(arbre);
   return 0;
   }
   */
