/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 14:02:36 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/18 13:29:03 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_ls.h"

int			ft_init_flags(t_flags **flags)
{
	if (!(*flags = malloc(sizeof(t_flags))))
		return (-1);
	(*flags)->arg = 0;
	(*flags)->l = 0;
	(*flags)->a = 0;
	(*flags)->r = 0;
	(*flags)->bigr = 0;
	(*flags)->t = 0;
	return (0);
}

int			ft_init_file(t_file **file, int i, char *arg)
{
	if (!(*file = malloc(sizeof(t_file))))
		return (-1);
	(*file)->total = 0;
	(*file)->subtree = NULL;
	(*file)->arg = 1;
	(*file)->error = NULL;
	if (i == 1)
	{
		(*file)->path = ft_strdup("./");
		(*file)->name = ft_strdup(".");
	}
	else
	{
		if (arg[0] == '/')
			(*file)->path = ft_strdup(arg);
		else
			(*file)->path = ft_strjoin("./", arg);
		(*file)->name = ft_strdup(arg);
	}
	if (!(*file)->path || !(*file)->name)
		return (-1);
	return (0);
}

void		ft_getfilestats(t_file **file, t_tree **errors, t_tree **tree,
		t_flags *flags)
{
	flags->arg++;
	if (lstat((*file)->path, &(*file)->sb) == -1)
	{
		(*file)->error = ft_strdup(strerror(errno));
		ft_fill_tree(file, errors, flags, 1);
	}
	else if (S_ISDIR((*file)->sb.st_mode) == 0)
		ft_fill_tree(file, errors, flags, 1);
	else
		ft_fill_tree(file, tree, flags, 0);
}

void		ft_print_errors(t_tree *tree, t_flags *flags)
{
	if (tree->left)
		ft_print_errors(tree->left, flags);
	if (tree->file->error != NULL)
	{
		ft_printf("ft_ls: %s: %s\n", tree->file->name, tree->file->error);
		ft_strdel(&(tree->file->error));
	}
	else
	{
		ft_print_name(tree, flags);
		ft_printf("\n");
	}
	if (tree->right)
		ft_print_errors(tree->right, flags);
}

void		ft_computeargs(t_tree *tree, t_flags **flags)
{
	if (tree != NULL)
	{
		if (tree->left)
			ft_computeargs(tree->left, flags);
		if (tree->file->subtree != NULL)
			ft_computeargs(tree->file->subtree, flags);
		if (S_ISDIR(tree->file->sb.st_mode))
			ft_getdirstats(&tree->file, tree->file->name, *flags);
		if (tree->right)
			ft_computeargs(tree->right, flags);
	}
}
