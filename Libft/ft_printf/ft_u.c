/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_u.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 20:09:28 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 02:23:49 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_u(t_param *ptr, va_list ap)
{
	unsigned long long li;

	if (!(li = va_arg(ap, unsigned long long int)) && ptr->prec == -1)
		ptr->string = ft_strdup("");
	else
	{
		if (!ptr->conv)
			li = (unsigned int)li;
		else if (ptr->conv == 5)
			li = (unsigned long int)li;
		else if (ptr->conv == 1)
			li = (unsigned char)li;
		else if (ptr->conv == 2)
			li = (unsigned short)li;
		else if (ptr->conv == 3)
			li = (uintmax_t)li;
		else if (ptr->conv == 4)
			li = (size_t)li;
		ptr->string = ft_ulongitoa(li);
	}
}
