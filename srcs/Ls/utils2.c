/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 13:58:56 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 14:57:37 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_uncap(char *str)
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

int			ft_error(t_file *file, char *error, t_flags *flags)
{
	if (flags->bigr == 1)
		ft_printf("%s:\n", file->path, error);
	ft_printf("ft_ls: %s: %s\n\n", file->name, error);
	return (-1);
}
