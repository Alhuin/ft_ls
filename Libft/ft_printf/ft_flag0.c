/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag0.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 21:49:49 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 03:39:14 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_flag0(t_param *ptr, int i, int neg, int esp)
{
	if (!ptr->string || ptr->type == 'S')
		return ;
	if (ptr->string[0] == '-')
	{
		ptr->string[0] = '0';
		neg++;
	}
	else if (ptr->string[0] == ' ')
	{
		ptr->string[0] = '0';
		esp++;
	}
	else if (ptr->string[0] == '+')
		ptr->string[0] = '0';
	else if (ptr->string[0] == '0' && (ptr->string[1] == 'x' ||
				ptr->string[1] == 'X'))
	{
		ptr->type = 'P';
		ptr->string[1] = '0';
	}
	while (i-- > 0)
		ptr->string = ft_strjoinfree("0", ptr->string, 2);
	ft_flag01(ptr, neg, esp);
}

void		ft_flag01(t_param *ptr, int neg, int esp)
{
	if (ft_findflag(ptr, 'x') != -1)
	{
		if (neg == 0)
			ptr->string[0] = '+';
		else
			ptr->string[0] = '-';
	}
	if (ft_findflag(ptr, '#') != -1 || ptr->type == 'p' || ptr->type == 'P')
	{
		if ((ptr->type == 'x' || ptr->type == 'X') && ft_atoi(ptr->string) != 0)
			ptr->string[1] = ptr->type;
		else if (ptr->type == 'P')
		{
			ptr->string[1] = 'x';
			ptr->type = 'a';
		}
		ft_eraseflag(ptr, '#');
	}
	if (neg == 1)
		ptr->string[0] = '-';
	if (esp == 1)
		ptr->string[0] = ' ';
	ft_eraseflag(ptr, '0');
}
