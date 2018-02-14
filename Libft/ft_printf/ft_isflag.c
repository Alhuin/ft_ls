/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isflag.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 18:29:03 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 19:29:30 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isflag(t_param *ptr)
{
	if (ptr->flag == '+' || ptr->flag == '-' || ptr->flag == '#' ||
			ptr->flag == '0' || ptr->flag == ' ')
		return (1);
	if (ptr->flag1 == '+' || ptr->flag1 == '-' || ptr->flag1 == '#' ||
			ptr->flag1 == '0' || ptr->flag1 == ' ')
		return (1);
	if (ptr->flag2 == '+' || ptr->flag2 == '-' || ptr->flag2 == '#' ||
			ptr->flag2 == '0' || ptr->flag2 == ' ')
		return (1);
	if (ptr->flag3 == '+' || ptr->flag3 == '-' || ptr->flag3 == '#' ||
			ptr->flag3 == '0' || ptr->flag3 == ' ')
		return (1);
	if (ptr->flag4 == '+' || ptr->flag4 == '-' || ptr->flag4 == '#' ||
			ptr->flag4 == '0' || ptr->flag4 == ' ')
		return (1);
	return (0);
}
