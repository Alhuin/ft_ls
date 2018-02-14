/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_findflag.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 15:36:32 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 15:38:39 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_findflag(t_param *ptr, char c)
{
	if (ptr->flag == c)
		return (0);
	else if (ptr->flag1 == c)
		return (1);
	else if (ptr->flag2 == c)
		return (2);
	else if (ptr->flag3 == c)
		return (3);
	else if (ptr->flag4 == c)
		return (4);
	else
		return (-1);
}
