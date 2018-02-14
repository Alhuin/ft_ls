/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 14:42:25 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 21:46:25 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_widthplus(t_param *ptr)
{
	if (ft_findflag(ptr, '+') != -1 || ft_findflag(ptr, ' ') != -1)
	{
		if (ft_atoi(ptr->string) > 0)
		{
			if (ft_findflag(ptr, '+') != -1)
			{
				ptr->string = ft_strjoinfree("+", ptr->string, 2);
				ft_eraseflag(ptr, '+');
				ft_eraseflag(ptr, ' ');
			}
			if (ft_findflag(ptr, ' ') != -1)
			{
				ptr->string = ft_strjoinfree(" ", ptr->string, 2);
				ft_eraseflag(ptr, ' ');
			}
		}
	}
}

static void		ft_prec1(t_param *ptr, int neg)
{
	if (neg == 1)
		ptr->string = ft_strjoinfree("-", ptr->string, 2);
	if (ft_findflag(ptr, '#') != -1 && ptr->string)
	{
		if (ptr->type == 'x' && ptr->prec > 1)
			ptr->string = ft_strjoinfree("0x", ptr->string, 2);
		else if (ptr->type == 'X' && ptr->prec > 1)
			ptr->string = ft_strjoinfree("0X", ptr->string, 2);
		else if ((ptr->type == 'o' || ptr->type == 'O') && ptr->prec > 1)
			ptr->string = ft_strjoinfree("0", ptr->string, 2);
		ft_eraseflag(ptr, '#');
	}
	ft_widthplus(ptr);
	if (ptr->type == 'p')
	{
		ptr->string = ft_strjoinfree("0x", ptr->string, 2);
		ptr->type = 'a';
	}
	ft_eraseflag(ptr, '0');
}

void			ft_prec(t_param *ptr)
{
	int i;
	int neg;

	neg = 0;
	if (!ptr->string || (ptr->type == '%'))
		return ;
	i = ptr->prec - ft_strlen(ptr->string);
	if (ptr->type != 'C')
	{
		if (ptr->type == 's')
			ptr->string = ft_precstr(ptr);
		if (i >= 0 && ptr->string[0] == '-')
		{
			ptr->string[0] = '0';
			neg++;
		}
		while (i-- > 0 && ptr->type != 'c')
		{
			ptr->string = ft_strjoinfree("0", ptr->string, 2);
			if (ptr->type == 'o' || ptr->type == 'O')
				ft_eraseflag(ptr, '#');
		}
		ft_prec1(ptr, neg);
	}
}
