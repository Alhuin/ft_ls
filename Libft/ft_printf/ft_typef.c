/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_typef.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 08:56:50 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 09:06:53 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_typef(t_param *ptr, va_list ap)
{
	double		d;
	int			prec;

	d = va_arg(ap, double);
	if (ptr->prec == 0)
		prec = 6;
	else
		prec = ptr->prec;
	ptr->string = ft_dtoa(d, prec);
	ptr->prec = 0;
}
