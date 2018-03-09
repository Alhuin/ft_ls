/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   abr.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:11 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 19:57:34 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_createnode(t_file **file, t_tree **tocreate)
{
	t_tree *node;

	if (!(node = malloc(sizeof(t_tree))))
		return (-1);
	(*node).file = *file;
	node->left = NULL;
	node->right = NULL;
	(*file)->alphatime = NULL;
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
