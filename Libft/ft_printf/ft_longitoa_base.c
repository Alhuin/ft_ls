/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_longitoa_base.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 17:36:58 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 23:07:30 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int			base_longconv(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'A');
	else
		return (nb + '0');
}

int			base_longintlen(long long nb, int base)
{
	int	i;

	i = 0;
	if (nb < 0 && base == 10)
		i++;
	if (nb == 0)
		i++;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char		*ft_longitoa_base(long long value, int base)
{
	long long		nb;
	int				i;
	char			*str;

	nb = value;
	i = base_longintlen(nb, base);
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
			str[0] = '-';
	}
	while (nb)
	{
		str[i--] = base_longconv(nb % base);
		nb /= base;
	}
	return (str);
}
