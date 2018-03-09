/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:17:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 19:32:30 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_getflags(t_flags **flags, char *arg)
{
	int i;

	i = 0;
	if (arg[i++] == '-')
	{
		while (arg[i])
		{
			if (arg[i] == 'l')
				(*flags)->l = 1;
			else if (arg[i] == 'a')
				(*flags)->a = 1;
			else if (arg[i] == 'r')
				(*flags)->r = 1;
			else if (arg[i] == 'R')
				(*flags)->bigr = 1;
			else if (arg[i] == 't')
				(*flags)->t = 1;
			else
				return (-1);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_computeargs(t_tree *tree, t_flags **flags)
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

int				ft_init_flags(t_flags **flags)
{
	if (!(*flags = malloc(sizeof(t_flags))))
		return (-1);
	(*flags)->elem = 0;
	(*flags)->arg = 0;
	(*flags)->l = 0;
	(*flags)->a = 0;
	(*flags)->r = 0;
	(*flags)->bigr = 0;
	(*flags)->t = 0;
	return (0);
}

void			ft_recursive(t_tree *tree, t_flags **flags)
{
	if (tree->left)
		ft_recursive(tree->left, flags);
	if (S_ISDIR(tree->file->sb.st_mode) && (tree->file->name[0] != '.' ||
		(*flags)->a == 1))
	{
		if (ft_getdirstats(&tree->file, tree->file->path, *flags) == 0)
			ft_recursive(tree->file->subtree, flags);
	}
	if (tree->right)
		ft_recursive(tree->right, flags);
}

int				main(int argc, char *argv[])
{
	t_flags		*flags;
	t_tree		*tree;
	t_file		*file;
	t_tree		*errors;
	int			i;

	errors = NULL;
	tree = NULL;
	i = 1;
	if (ft_init_flags(&flags) == -1)
		return (-1);
	while (argv[i] && ft_getflags(&flags, argv[i]) == 1)
		i++;
	while (i < argc || (i == argc && flags->arg == 0))
	{
		flags->arg++;
		if (!(file = malloc(sizeof(t_file))))
			return (-1);
		file->total = 0;
		file->subtree = NULL;
		file->arg = 1;
		file->error = NULL;
		if (i == argc)
		{
			if (!(file->path = ft_strdup("./")))
				return (-1);
			if (!(file->name = ft_strdup(".")))
				return (-1);
		}
		else
		{
			if (!(file->path = ft_strjoin("./", argv[i])))
				return (-1);
			if (!(file->name = ft_strdup(argv[i])))
				return (-1);
		}
		if (lstat(file->path, &file->sb) == -1)
		{
			file->error = ft_strdup(strerror(errno));
			ft_fill_tree(&file, &errors, flags, 1);
		}
		else if (S_ISDIR(file->sb.st_mode) == 0)
			ft_fill_tree(&file, &errors, flags, 1);
		else
			ft_fill_tree(&file, &tree, flags, 0);
		i++;
	}
	if (errors)
	{
		ft_print_errors(errors, flags);
		ft_printf("\n");
	}
	ft_computeargs(tree, &flags);
	if (flags->bigr == 1)
		ft_recursive(tree->file->subtree, &flags);
	if (tree)
		ft_free_tree(&tree);
	if (errors)
		ft_free_tree(&errors);
	free(flags);
	return (0);
}

void		ft_print_errors(t_tree *tree, t_flags *flags)
{
	if (tree->left)
		ft_print_errors(tree->left, flags);
	if (tree->file->error)
	{
		ft_printf("ft_ls: %s: %s\n", tree->file->name, tree->file->error);
		ft_strdel(&tree->file->error);
	}
	else
		ft_print_name(tree, 0, flags);
	if (tree->right)
		ft_print_errors(tree->right, flags);
}

void		ft_free_node(t_tree **node)
{
	if ((*node)->file->subtree)
		ft_free_tree(&(*node)->file->subtree);
	ft_strdel(&(*node)->file->name);
	ft_strdel(&(*node)->file->path);
	free((*node)->file);
	free(*node);
}

void		ft_free_tree(t_tree **tree)
{
	if ((*tree)->left)
		ft_free_tree(&(*tree)->left);
	if ((*tree)->right)
		ft_free_tree(&(*tree)->right);
	ft_free_node(tree);
}
