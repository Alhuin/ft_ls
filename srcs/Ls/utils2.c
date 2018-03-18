/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 13:58:56 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/18 16:11:23 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_ls.h"

char				*ft_uncap(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int					ft_error(t_file *file, char *error, t_flags *flags)
{
	if (flags->bigr == 1)
		ft_printf("%s:\n", file->path, error);
	ft_printf("ft_ls: %s: %s\n\n", file->name, error);
	return (-1);
}

int					ft_print_help(t_flags **flags)
{
	char	*line;
	int		fd;

	(*flags)->help = 1;
	fd = open("srcs/Ls/man.txt", O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (-1);
}

int					ft_checkflag(char c, t_flags **flags)
{
	if (c == 'l')
		(*flags)->l = 1;
	else if (c == 'a')
		(*flags)->a = 1;
	else if (c == 'f')
	{
		(*flags)->a = 1;
		(*flags)->f = 1;
	}
	else if (c == 'u')
		(*flags)->u = 1;
	else if (c == 'd')
		(*flags)->d = 1;
	else if (c == '1')
		(*flags)->un = 1;
	else if (c == 'r')
		(*flags)->r = 1;
	else if (c == 'R')
		(*flags)->bigr = 1;
	else if (c == 't')
		(*flags)->t = 1;
	else
		return (-1);
	return (1);
}

void				ft_addnode(t_file **file, t_tree **tree)
{
	if (*tree == NULL)
		ft_createnode(file, tree);
	else if ((*tree)->right)
		ft_addnode(file, &(*tree)->right);
	else
		ft_createnode(file, &(*tree)->right);
}
