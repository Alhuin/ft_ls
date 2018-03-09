/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:13:57 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 14:04:24 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static int			ft_printbigc(t_param *ptr, int ret)
{
	if (ft_findflag(ptr, '-') != -1)
		ret += ft_putwchar(ptr->wc);
	while (ptr->width-- > ft_wclen(ptr->wc))
	{
		if (ft_findflag(ptr, '0') != -1 || ft_findflag(ptr, 'O') != -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
	}
	if (ft_findflag(ptr, '-') == -1)
		ret += ft_putwchar(ptr->wc);
	return (ret);
}

static int			ft_printw(t_param *ptr, int ret)
{
	if (ft_findflag(ptr, '-') != -1)
		ret += ft_putwchar('\0');
	while (ptr->width-- > 1)
	{
		if (ft_findflag(ptr, '0') != -1 || ft_findflag(ptr, 'O') != -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
	}
	if (ft_findflag(ptr, '-') == -1)
		ret += ft_putwchar('\0');
	return (ret);
}

static int			ft_printbigs(t_param *ptr, int ret)
{
	if (ft_findflag(ptr, '-') != -1)
		ret += ft_putwstr(ptr->wstring);
	while (ptr->width-- > ft_wstrlen(ptr->wstring))
	{
		if (ft_findflag(ptr, '0') != -1 || ft_findflag(ptr, 'O') != -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
	}
	if (ft_findflag(ptr, '-') == -1)
		ret += ft_putwstr(ptr->wstring);
	return (ret);
}

int					ft_print(t_param *ptr, int ret)
{
	if (ptr->type != 'C' && ptr->type != 'w' && !(ptr->type == 'c' &&
				ptr->conv == 5) && ptr->type != 'S' && (!(ptr->type == 's' &&
						ptr->conv == 5)))
	{
		write(1, ptr->string, ptr->size);
		ret += ptr->size;
	}
	else
	{
		if (ptr->type == 'C' || (ptr->type == 'c' && ptr->conv == 5))
			ret = ft_printbigc(ptr, ret);
		if (ptr->type == 'w')
			ret = ft_printw(ptr, ret);
		else if (ptr->type == 'S' || (ptr->type == 's' && ptr->conv == 5))
			ret = ft_printbigs(ptr, ret);
	}
	return (ret);
}
