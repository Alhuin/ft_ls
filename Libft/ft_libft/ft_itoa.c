/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 16:26:57 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 16:28:50 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*ret;
	int				size;
	long int		i;

	i = n;
	size = ft_intlen(i);
	if (!(ret = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ret[size] = '\0';
	if (i < 0)
	{
		i = -i;
		ret[0] = '-';
	}
	if (i == 0)
		ret[0] = '0';
	while (i)
	{
		ret[size - 1] = i % 10 + 48;
		i = i / 10;
		size--;
	}
	return (ret);
}
