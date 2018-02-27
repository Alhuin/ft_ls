/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putflag.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/22 19:00:03 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 05:08:55 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putflag(char c, t_param *ptr)
{
	if (ptr->flag == 'a' && ft_findflag(ptr, c) == -1)
		ptr->flag = c;
	else if (ptr->flag1 == 'a' && ft_findflag(ptr, c) == -1)
		ptr->flag1 = c;
	else if (ptr->flag2 == 'a' && ft_findflag(ptr, c) == -1)
		ptr->flag2 = c;
	else if (ptr->flag3 == 'a' && ft_findflag(ptr, c) == -1)
		ptr->flag3 = c;
	else if (ptr->flag4 == 'a' && ft_findflag(ptr, c) == -1)
		ptr->flag4 = c;
}
