/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getflags.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 21:44:51 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 08:51:17 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void		ft_getflags(char **str, t_param **begin)
{
	t_param *ptr;

	ptr = *begin;
	while (ptr->next)
		ptr = ptr->next;
	while (**str == '+' || **str == '-' || **str == ' '
			|| **str == '#' || **str == '0')
	{
		if (**str == '#')
			ft_putflag(**str, ptr);
		else if (**str == '0')
			ft_putflag(**str, ptr);
		else if (**str == ' ')
			ft_putflag(**str, ptr);
		else if (**str == '+')
			ft_putflag(**str, ptr);
		else if (**str == '-')
			ft_putflag(**str, ptr);
		*str += 1;
	}
}
