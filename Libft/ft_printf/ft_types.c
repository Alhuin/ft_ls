/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_types.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 19:11:30 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 02:35:52 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void		ft_types(t_param *ptr, va_list ap)
{
	char*str;

	str = NULL;
	if (ptr->type == 'S' || (ptr->type == 's' && ptr->conv == 5))
		ft_bigs(ptr, ap);
	else
	{
		if (!(str = va_arg(ap, char *)) && ptr->prec == -1)
			ptr->string = ft_strdup("");
		else
		{
			if (!(str))
				ptr->string = ft_strdup("(null)");
			else
				ptr->string = ft_strdup(str);
		}
	}
}
