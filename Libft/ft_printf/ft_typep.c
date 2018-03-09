/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_typep.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 19:03:30 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 16:54:10 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_typep(t_param *ptr, va_list ap)
{
	unsigned long u;

	u = 0;
	if (!(u = va_arg(ap, unsigned long int)) && ptr->prec == -1)
		ptr->string = ft_strdup("");
	else
		ptr->string = ft_uncap(ft_longitoa_base(u, 16));
}
