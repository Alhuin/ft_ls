/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getconv.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 15:19:09 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 02:10:07 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_getconv(char **str, t_param **begin)
{
	t_param *ptr;

	ptr = *begin;
	while (ptr->next)
		ptr = ptr->next;
	while (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
	{
		if (**str == 'h')
			((*(*str + 1) == 'h') ? ft_whichconv(1, str, ptr) :
			ft_whichconv(2, str, ptr));
		else if (**str == 'l')
		{
			if (*(*str + 1) == 'l')
				ft_whichconv(6, str, ptr);
			else
				ft_whichconv(5, str, ptr);
		}
		else if (**str == 'j')
			ft_whichconv(3, str, ptr);
		else if (**str == 'z')
			ft_whichconv(4, str, ptr);
	}
}
