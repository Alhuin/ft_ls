/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getwidthprec.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 15:22:12 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 06:12:02 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_getwild(char **str, t_param *ptr, va_list ap, char c)
{
	int i;

	i = 0;
	if ((i = va_arg(ap, int)) < 0)
	{
		if (c == 'w')
		{
			i = -i;
			ft_putflag('-', ptr);
		}
		else
			i = 123456789;
	}
	if (c == 'w')
		ptr->width = i;
	else
	{
		if (i == 0)
			ptr->prec = -1;
		else if (i == 123456789)
			ptr->prec = 0;
		else
			ptr->prec = i;
	}
	*str += 1;
}

static void		ft_getwidth(char **str, t_param *ptr, va_list ap)
{
	if (**str == '*')
		ft_getwild(str, ptr, ap, 'w');
	else if (**str >= '0' && **str <= '9')
	{
		ptr->width = ft_atoi(*str);
		*str = *str + ft_intlen(ptr->width);
	}
	if (**str == '*')
		ft_getwild(str, ptr, ap, 'w');
	else if (**str >= '0' && **str <= '9')
	{
		ptr->width = ft_atoi(*str);
		*str = *str + ft_intlen(ptr->width);
	}
}

static void		ft_getprec(char **str, t_param *ptr, va_list ap)
{
	while (**str == '.')
	{
		*str += 1;
		if (**str == '*')
			ft_getwild(str, ptr, ap, 'p');
		else if (**str >= '1' && **str <= '9')
		{
			ptr->prec = ft_atoi(*str);
			*str = *str + ft_intlen(ptr->prec);
		}
		else
		{
			ptr->prec = -1;
			if (**str == '0')
				*str += 1;
		}
	}
}

void			ft_getwidthprec(char **str, t_param **begin, va_list ap)
{
	t_param *ptr;

	ptr = *begin;
	while (ptr->next)
		ptr = ptr->next;
	ft_getwidth(str, ptr, ap);
	ft_getprec(str, ptr, ap);
}
