/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_doflags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 22:01:20 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 13:59:55 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void		ft_doflags(t_param *ptr, int i)
{
	if (ft_findflag(ptr, '0') != -1)
	{
		if (ft_findflag(ptr, '-') != -1)
		{
			while (i-- > 0)
				ptr->string = ft_strjoinfree(ptr->string, " ", 1);
			ft_eraseflag(ptr, '-');
			ft_eraseflag(ptr, '0');
		}
		else
			ft_flag0(ptr, i, 0, 0);
	}
	ft_doflags2(ptr, i);
}

void		ft_doflags2(t_param *ptr, int i)
{
	if (ft_findflag(ptr, '-') != -1 && ptr->type != 'w' && ptr->type != 'C' &&
	!(ptr->type == 'c' && ptr->conv == 5) && ptr->type != 'S' &&
	!(ptr->type == 's' && ptr->conv == 5))
	{
		while (i-- > 0)
			ptr->string = ft_strjoinfree(ptr->string, " ", 1);
		ft_eraseflag(ptr, '-');
	}
	if (ft_findflag(ptr, '#') != -1)
	{
		while (i-- > 0)
			ptr->string = ft_strjoinfree(" ", ptr->string, 2);
		ft_eraseflag(ptr, '#');
	}
	if (ptr->type == 'l')
		while ((i = ptr->width - (int)ft_strlen(ptr->string)) > 1)
		{
			ptr->string = ft_strjoinfree(" ", ptr->string, 2);
			i--;
		}
}
