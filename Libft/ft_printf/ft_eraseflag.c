/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_eraseflag.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 19:01:06 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/11 19:03:00 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_eraseflag(t_param *ptr, char c)
{
	if (ptr->flag == c)
		ptr->flag = 'a';
	if (ptr->flag1 == c)
		ptr->flag1 = 'a';
	if (ptr->flag2 == c)
		ptr->flag2 = 'a';
	if (ptr->flag3 == c)
		ptr->flag3 = 'a';
	if (ptr->flag4 == c)
		ptr->flag4 = 'a';
}
