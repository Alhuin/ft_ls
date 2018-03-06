/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 16:26:58 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 16:31:03 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		base_conv(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'A');
	else
		return (nb + '0');
}

int		base_intlen(int nb, int base)
{
	int i;

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

char	*ft_itoa_base(int value, int base)
{
	long	nb;
	int		i;
	char	*str;

	nb = (long)value;
	i = base_intlen(nb, base);
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
		str[i--] = base_conv(nb % base);
		nb /= base;
	}
	return (str);
}
