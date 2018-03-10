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


static void			ft_recursive(t_tree *tree, t_flags **flags)
{
	if (tree->left)
		ft_recursive(tree->left, flags);
	if (S_ISDIR(tree->file->sb.st_mode) && (tree->file->name[0] != '.' ||
				(*flags)->a == 1))
	{
		if (ft_strcmp(tree->file->name, "..") != 0 &&
			ft_strcmp(tree->file->name, ".") != 0)
			if (ft_getdirstats(&tree->file, tree->file->path, *flags) == 0)
				ft_recursive(tree->file->subtree, flags);
	}
	if (tree->right)
		ft_recursive(tree->right, flags);
}

static void			ft_print(t_tree *errors, t_tree *tree, t_flags *flags)
{
	if (errors)
	{
		ft_print_errors(errors, flags);
		ft_printf("\n");
	}
	ft_computeargs(tree, &flags);
	if (flags->bigr == 1)
		ft_recursive(tree->file->subtree, &flags);
}

static int		ft_free(t_tree **errors, t_tree **tree, t_flags **flags)
{
	if (*tree)
		ft_free_tree(&(*tree));
	if (*errors)
		ft_free_tree(&(*errors));
	free(*flags);
	return (-1);
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
		return (ft_free(&errors, &tree, &flags));
	while (argv[i] && ft_getflags(&flags, argv[i]) == 1)
		i++;
	while (i < argc || (i == argc && flags->arg == 0))
	{
		if (ft_init_file(&flags, &file, (i == argc ? 1 : 0), argv[i]) == -1)
			return (ft_free(&errors, &tree, &flags));
		ft_getfilestats(&file, &errors, &tree, flags);
		i++;
	}
	ft_print(errors, tree, flags);
	ft_free(&errors, &tree, &flags);
	return (0);
}


