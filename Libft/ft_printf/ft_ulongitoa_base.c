/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulongitoa_base.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 17:42:13 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 18:32:53 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int			base_uconv(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'A');
	else
		return (nb + '0');
}

int			base_ulongintlen(unsigned long long nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char		*ft_ulongitoa_base(unsigned long long value, int base)
{
	unsigned long long	nb;
	int					i;
	char				*str;

	nb = value;
	i = base_ulongintlen(nb, base);
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[i--] = base_uconv(nb % base);
		nb /= base;
	}
	return (str);
}
