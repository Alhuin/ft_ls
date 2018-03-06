/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulongitoa.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 18:33:26 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 02:30:57 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_ulongintlen(unsigned long long nb)
{
	int i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_ulongitoa(unsigned long long n)
{
	char				*ret;
	int					size;
	unsigned long long	i;

	i = n;
	size = ft_ulongintlen(i);
	if (!(ret = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ret[size] = '\0';
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
