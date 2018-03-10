/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   abr.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:11 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 15:31:49 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_createnode(t_file **file, t_tree **tocreate)
{
	t_tree *node;

	if (!(node = malloc(sizeof(t_tree))))
		return (-1);
	(*node).file = *file;
	node->left = NULL;
	node->right = NULL;
	(*file)->subtree = NULL;
	*tocreate = node;
	return (0);
}

int			ft_sort(t_file **file, t_tree **node, int(*fn)())
{
	if (*node == NULL)
		return (ft_createnode(file, node));
	else
	{
		if (fn(*file, (*node)->file) >= 0)
		{
			if ((*node)->right)
				ft_sort(file, &(*node)->right, fn);
			else
				return (ft_createnode(file, &(*node)->right));
		}
		if (fn(*file, (*node)->file) < 0)
		{
			if ((*node)->left)
				ft_sort(file, &(*node)->left, fn);
			else
				return (ft_createnode(file, &(*node)->left));
		}
	}
	return (0);
}

int			ft_double_sort(t_file **file, t_tree **node, int(*f1)(), int(*f2)())
{
	if (*node == NULL)
		return (ft_createnode(file, node));
	else
	{
		if (f1(*file, (*node)->file) > 0)
			((*node)->right ? ft_double_sort(file, &(*node)->right, f1, f2) :
				ft_createnode(file, &(*node)->right));
		else if (f1(*file, (*node)->file) < 0)
			((*node)->left ? ft_double_sort(file, &(*node)->left, f1, f2) :
				ft_createnode(file, &(*node)->left));
		else if (f2(*file, (*node)->file) > 0)
			((*node)->right ? ft_double_sort(file, &(*node)->right, f1, f2) :
				ft_createnode(file, &(*node)->right));
		else if (f2(*file, (*node)->file) < 0)
			((*node)->left ? ft_double_sort(file, &(*node)->left, f1, f2) :
				ft_createnode(file, &(*node)->left));
	}
	return (0);
}

void		ft_free_node(t_tree **node)
{
	if ((*node)->file->name)
		ft_strdel(&(*node)->file->name);
	if ((*node)->file->path)
		ft_strdel(&(*node)->file->path);
	if ((*node)->file)
	{
		free((*node)->file);
		(*node)->file = NULL;
	}
	free(*node);
	*node = NULL;
}

void		ft_free_tree(t_tree **tree)
{
	if ((*tree)->left)
		ft_free_tree(&(*tree)->left);
	if ((*tree)->right)
		ft_free_tree(&(*tree)->right);
	if ((*tree)->file->subtree)
		ft_free_tree(&(*tree)->file->subtree);
	if (*tree)
		ft_free_node(tree);
}
