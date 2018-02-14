/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wprec.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 18:16:50 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 02:12:33 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_wprec(t_param *ptr)
{
	if (ptr->prec < ft_wstrlen(ptr->wstring))
		ptr->wstring = ft_wstrndup(ptr->wstring, ptr->prec);
}
