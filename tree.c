/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   abr.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:11 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 15:33:30 by jjanin-r    ###    #+. /#+    ###.fr     */
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

int				ft_traddnode(t_file **file, t_tree **node)
{
	t_file *new = NULL;
	if (*node == NULL)
		return (ft_createnode(file, node));
	else
	{
		if ((*file)->sb.st_mtime == (*node)->file->sb.st_mtime)
		{
			if ((*node)->file->alphatime == NULL)
			{
				new = malloc(sizeof(t_file));
				new->name = ft_strdup((*node)->file->name);
				new->path = ft_strdup((*node)->file->path);
				new->sb = (*node)->file->sb;
				new->subtree = NULL;
				new->alphatime = NULL;
				ft_raddnode(&new, &(*node)->file->alphatime);
			}
			return (ft_raddnode(file, &(*node)->file->alphatime));
		}
		if ((*file)->sb.st_mtime < (*node)->file->sb.st_mtime)
		{
			if ((*node)->left)
				ft_traddnode(file, &(*node)->left);
			else
				return (ft_createnode(file, &(*node)->left));
		}
		if ((*file)->sb.st_mtime == (*node)->file->sb.st_mtime)
			ft_raddnode(file, node);
		if ((*file)->sb.st_mtime > (*node)->file->sb.st_mtime)
		{
			if ((*node)->right)
				ft_traddnode(file, &(*node)->right);
			else
				return (ft_createnode(file, &(*node)->right));
		}
	}
	return (0);
}

int				ft_taddnode(t_file **file, t_tree **node)
{
	t_file *new = NULL;
	if (*node == NULL)
		return (ft_createnode(file, node));
	else
	{
		if ((*file)->sb.st_mtime == (*node)->file->sb.st_mtime)
		{
			if ((*node)->file->alphatime == NULL)
			{
				new = malloc(sizeof(t_file));
				new->name = ft_strdup((*node)->file->name);
				new->path = ft_strdup((*node)->file->path);
				new->sb = (*node)->file->sb;
				new->subtree = NULL;
				new->alphatime = NULL;
				ft_addnode(&new, &(*node)->file->alphatime);
			}
			return (ft_addnode(file, &(*node)->file->alphatime));
		}
		if ((*file)->sb.st_mtime > (*node)->file->sb.st_mtime)
		{
			if ((*node)->left)
				ft_taddnode(file, &(*node)->left);
			else
				return (ft_createnode(file, &(*node)->left));
		}
		if ((*file)->sb.st_mtime < (*node)->file->sb.st_mtime)
		{
			if ((*node)->right)
				ft_taddnode(file, &(*node)->right);
			else
				return (ft_createnode(file, &(*node)->right));
		}
	}
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


