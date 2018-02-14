/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 08:34:48 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 09:34:11 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_dtoa(double nbr, int prec)
{
	char			*ret;
	char			*d;
	long long int	nb;
	float			dec;
	int				i;

	nb = nbr / 1;
	if ((dec = nbr - nb) < 0)
		dec = -dec;
	i = prec;
	while (i-- > 0)
		dec *= 10;
	dec /= 1;
	d = ft_longitoa(dec);
	while ((i = prec - (int)ft_strlen(d)) > 0)
		d = ft_strjoinfree(d, "0", 1);
	if (prec == 0)
		ret = ft_itoa(nb);
	else
	{
		ret = ft_strjoinfree(ft_longitoa(nb), ".", 1);
		ret = ft_strjoinfree(ret, d, 3);
	}
	return (ret);
}
