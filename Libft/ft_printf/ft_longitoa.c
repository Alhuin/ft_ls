/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 17:28:45 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:28:43 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_longintlen(long long int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_longitoa(long long int n)
{
	char			*ret;
	int				size;

	size = ft_longintlen(n);
	if (!(ret = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ret[size] = '\0';
	if (n < -9223372036854775807)
	{
		ret[1] = '9';
		n = n + 9000000000000000000;
	}
	if (n < 0)
	{
		n = -n;
		ret[0] = '-';
	}
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		ret[(size--) - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (ret);
}
