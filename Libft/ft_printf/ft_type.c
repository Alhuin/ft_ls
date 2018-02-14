/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 20:55:54 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 08:56:36 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_validtype(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'C' || c == 'c' || c == '%' ||
			c == 'f' || c == 'F' || c == 'n' || c == 'b')
		return (1);
	else
		return (0);
}

static void		ft_gotype(t_param *ptr, char **str, va_list ap)
{
	ptr->type = **str;
	if (**str == 's' || **str == 'S')
		ft_types(ptr, ap);
	else if (**str == '%')
		ptr->string = ft_charstr('%');
	else if (**str == 'c' || **str == 'C')
		ft_typec(ptr, ap);
	else if (**str == 'o' || **str == 'O')
		ft_typeo(ptr, ap);
	else if (**str == 'p')
		ft_typep(ptr, ap);
	else if (**str == 'u' || **str == 'U')
		ft_typeu(ptr, ap);
	else if (**str == 'x' || **str == 'X')
		ft_typex(str, ptr, ap);
	else if (**str == 'd' || **str == 'i' || **str == 'D')
		ft_typed(ptr, ap);
	else if (**str == 'f' || **str == 'F')
		ft_typef(ptr, ap);
	else if (**str == 'n')
		ptr->ptr = va_arg(ap, int *);
	else if (**str == 'b')
		ptr->string = ft_longitoa_base(va_arg(ap, long long int), 2);
	*str += 1;
}

int				ft_type(char **str, t_param **begin, va_list ap)
{
	t_param *ptr;

	ptr = *begin;
	while (ptr->next)
		ptr = ptr->next;
	if (ft_validtype(**str))
		ft_gotype(ptr, str, ap);
	else
	{
		if (ptr->width == 0 && ptr->prec == 0)
		{
			ft_lsdellast(begin);
			ptr = NULL;
			return (-1);
		}
		else
		{
			ptr->string = ft_charstr(**str);
			*str += 1;
			ptr->type = 'l';
			ft_width(ptr);
			ft_prec(ptr);
		}
	}
	return (0);
}
