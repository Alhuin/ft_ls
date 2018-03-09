/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_typeo.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 18:53:14 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 02:13:55 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_typeo(t_param *ptr, va_list ap)
{
	unsigned long long int		li;

	if (!(li = va_arg(ap, unsigned long long int)) && ptr->prec == -1)
	{
		if (ft_findflag(ptr, '#') != -1)
			ptr->string = ft_strdup("0");
		else
			ptr->string = ft_strdup("");
	}
	else
	{
		if (ptr->type == 'O' || (ptr->conv == 5 && ptr->type == 'o'))
			li = (unsigned long)li;
		else if (!(ptr->conv))
			li = (unsigned int)li;
		else if (ptr->conv == 1)
			li = (unsigned char)li;
		else if (ptr->conv == 2)
			li = (unsigned short)li;
		else if (ptr->conv == 3)
			li = (uintmax_t)li;
		else if (ptr->conv == 4)
			li = (size_t)li;
		ptr->string = ft_ulongitoa_base(li, 8);
	}
}
