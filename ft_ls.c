/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:17:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 16:45:54 by jjanin-r    ###    #+. /#+    ###.fr     */
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

int				ft_getargs(t_file **file, char *arg, char *pref, int a)
{
	(*file)->arg = a;
	(*file)->path = ft_strjoin((pref ? pref : "./"), arg);
	if (!((*file)->name = ft_strdup(arg)))
		return (-1);
	lstat((*file)->path, &(*file)->sb);
	return (0);
}

void	ft_computeargs(t_tree *tree, t_flags **flags)
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

int				main(int argc, char *argv[])
{
	t_flags		*flags;
	t_tree		*tree;
	t_file		*file;
	int			i;

	tree = NULL;
	i = 1;
	if (!(flags = malloc(sizeof(t_flags))))
		return (-1);
	flags->a = 0;
	while (argv[i] && ft_getflags(&flags, argv[i]) == 1)
		i++;
	flags->arg = 0;
	while (i < argc || (i == argc && flags->arg == 0))
	{
		flags->arg++;
		if (!(file = malloc(sizeof(t_file))))
			return (-1);
		file->total = 0;
		file->subtree = NULL;
		file->alphatime = NULL;
		ft_getargs(&file, (i == argc ? "./" : argv[i]), NULL, 1);
		ft_fill_tree(&file, &tree, flags);
		i++;
	}
	ft_computeargs(tree, &flags);
	return (0);
}
