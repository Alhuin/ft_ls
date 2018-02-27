/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_replaceflag.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 18:47:26 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 19:06:15 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_replaceflag(t_param *ptr, char c, char d)
{
	if (ptr->flag == c)
		ptr->flag = d;
	else if (ptr->flag1 == c)
		ptr->flag1 = d;
	else if (ptr->flag2 == c)
		ptr->flag2 = d;
	else if (ptr->flag3 == c)
		ptr->flag3 = d;
	else if (ptr->flag4 == c)
		ptr->flag4 = d;
}
