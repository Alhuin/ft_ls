/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_checkerror.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 13:56:38 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 13:58:08 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_checkerror(t_param **begin)
{
	t_param		*ptr;

	ptr = *begin;
	while (ptr)
	{
		if (ptr->error == 1)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
