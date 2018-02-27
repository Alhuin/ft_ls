/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_typec.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 17:58:26 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 02:34:59 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_typec(t_param *ptr, va_list ap)
{
	long int c;

	if (ptr->type == 'c' && ptr->conv != 5)
	{
		if (!(c = va_arg(ap, long int)))
		{
			ptr->wc = '\0';
			ptr->type = 'w';
		}
		else
			ptr->string = ft_charstr((int)c);
	}
	else
		ft_bigc(ptr, ap);
}
