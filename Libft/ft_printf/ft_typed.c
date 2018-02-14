/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_typex.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 18:59:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:28:17 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_typed(t_param *ptr, va_list ap)
{
	long long int		li;

	if (!(li = va_arg(ap, long long int)) && ptr->prec == -1)
		ptr->string = ft_strdup("");
	else
	{
		if (ptr->type == 'D')
			li = (long int)li;
		else if (!(ptr->conv))
			li = (int)li;
		else if (ptr->conv == 5)
			li = (long)li;
		else if (ptr->conv == 1)
			li = (signed char)li;
		else if (ptr->conv == 2)
			li = (short)li;
		else if (ptr->conv == 3)
			li = (intmax_t)li;
		else if (ptr->conv == 4)
			li = (size_t)li;
		ptr->string = ft_longitoa(li);
	}
}
