/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   abr.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:11 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 01:18:49 by jjanin-r    ###    #+. /#+    ###.fr     */
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
	*tocreate = node;
	return (0);
}

int				ft_addnode(t_file **file, t_tree **node)
{
	if (*node == NULL)
		return (ft_createnode(file, node));
	else
	{
		if (ft_strcmp((*file)->name, (*node)->file->name) > 0)
		{
			if ((*node)->right)
				ft_addnode(file, &(*node)->right);
			else
				return (ft_createnode(file, &(*node)->right));
		}
		if (ft_strcmp((*file)->name, (*node)->file->name) < 0)
		{
			if ((*node)->left)
				ft_addnode(file, &(*node)->left);
			else
				return (ft_createnode(file, &(*node)->left));
		}
	}
	return (0);
}

int				ft_raddnode(t_file **file, t_tree **node)
{
	if (*node == NULL)
		return (ft_createnode(file, node));
	else
	{
		if (ft_strcmp((*file)->name, (*node)->file->name) > 0)
		{
			if ((*node)->left)
				ft_raddnode(file, &(*node)->left);
			else
				return (ft_createnode(file, &(*node)->left));
		}
		if (ft_strcmp((*file)->name, (*node)->file->name) < 0)
		{
			if ((*node)->right)
				ft_raddnode(file, &(*node)->right);
			else
				return (ft_createnode(file, &(*node)->right));
		}
	}
	return (0);
}

void			ft_print_name(t_tree *tree, int lengh, t_flags *flags)
{
	if (flags->l != 1)
	{
		if (tree->file->name[0] != '.' || flags->a == 1)
		{
			if (S_ISDIR(tree->file->sb.st_mode))
				ft_printf("{bcyan}%-*s{eoc}", lengh, tree->file->name);
			else if (tree->file->sb.st_mode & S_IXUSR)
				ft_printf("{red}%-*s{eoc}", lengh, tree->file->name);
			else
				ft_printf("%-*s", lengh, tree->file->name);
		}
	}
	else
		ft_printl(&(tree->file), &flags);
}

void			ft_print_tree(t_tree *arbre, int lengh, t_flags *flags)
{
	if (arbre != NULL)
	{
		if (arbre->left)
			ft_print_tree(arbre->left, lengh, flags);
		ft_print_name(arbre, lengh, flags);
		if (arbre->right)
			ft_print_tree(arbre->right, lengh, flags);
	}
}

void			ft_rev_print_tree(t_tree *arbre, int lengh, t_flags *flags)
{
	if (arbre != NULL)
	{
		if (arbre->right)
			ft_print_tree(arbre->right, lengh, flags);
		ft_print_name(arbre, lengh, flags);
		if (arbre->left)
			ft_print_tree(arbre->left, lengh, flags);
	}
}

void			ft_computeargs(t_tree *tree, t_flags **flags)
{
	if (tree != NULL)
	{
		if (tree->left)
			ft_computeargs(tree->left, flags);
		ft_getdirstats(&tree->file, tree->file->name, *flags);
		if (tree->right)
			ft_computeargs(tree->right, flags);
	}
}
