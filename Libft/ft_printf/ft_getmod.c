/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getmod.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 03:09:33 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 22:08:02 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_getmod(t_param **begin, char **str, va_list ap, char *ptr)
{
	*str = *str + 1;
	if (!(ft_lstpush(begin, ft_node())))
	{
		ft_lsdel(begin);
		ft_strdel(&ptr);
		exit(-1);
	}
	ft_getflags(str, begin);
	ft_getwidthprec(str, begin, ap);
	ft_getflags(str, begin);
	ft_getconv(str, begin);
	ft_getflags(str, begin);
	if (ft_type(str, begin, ap) != -1)
		ft_compute(begin);
}
