/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_compute.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/22 18:49:05 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 11:38:40 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_compute(t_param **begin)
{
	t_param	*ptr;
	int		size;

	size = 0;
	ptr = *begin;
	while (ptr->next)
	{
		size += ptr->size;
		ptr = ptr->next;
	}
	if (ptr->type == 'n')
		*(ptr->ptr) = size;
	if (ptr->type == 's' && ptr->conv != 5 && ptr->prec != 0)
	{
		ptr->string = ft_precstr(ptr);
		ft_width(ptr);
	}
	if (ptr->prec == -1)
		ft_replaceflag(ptr, '0', 'O');
	if (ptr->prec != 0 && ptr->prec != -1)
		ft_prec(ptr);
	if (ft_findflag(ptr, '#') != -1)
		ft_flagdiese(ptr);
	ft_compute1(ptr);
	ptr->size = ft_strlen(ptr->string);
}

void	ft_compute1(t_param *ptr)
{
	if (ft_findflag(ptr, '+') != -1 && ptr->type != 'C' && ptr->type != 'o'
			&& ptr->type != 'O' && ptr->type != 's' && ptr->type != 'p' &&
			ptr->type != 'u' && ptr->type != 'x' && ptr->type != 'X' &&
			ptr->type != '%' && ptr->type != 'b')
	{
		if (ft_atoi(ptr->string) >= 0)
			ptr->string = ft_strjoinfree("+", ptr->string, 2);
		ft_replaceflag(ptr, '+', 'x');
	}
	if (ft_findflag(ptr, ' ') != -1 && ft_findflag(ptr, 'x') == -1
			&& ptr->type != 'C' && ptr->type != 'u' && ptr->type != 'S' &&
			ptr->type != 'c' && ptr->type != 's' && ptr->type != 'p' &&
			ptr->type != 'o' && ptr->type != 'x' && ptr->type != 'X' &&
			ptr->type != 'b')
		if ((ft_atoi(ptr->string) >= 0) && ptr->type != '%')
		{
			ptr->string = ft_strjoinfree(" ", ptr->string, 2);
			ft_eraseflag(ptr, ' ');
		}
	if (ptr->width >= (int)ft_strlen(ptr->string) && ptr->type != 'S')
		ft_width(ptr);
	if (ptr->type == 'p')
		ptr->string = ft_strjoinfree("0x", ptr->string, 2);
	if (ptr->wstring && ptr->prec && ptr->type)
		ft_wprec(ptr);
}
