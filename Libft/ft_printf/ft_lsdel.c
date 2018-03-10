/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lsdel.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/13 19:12:50 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 11:50:57 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lsdel(t_param **begin)
{
	t_param	*ptr;

	while (*begin != NULL)
	{
		ptr = (*begin)->next;
		if ((*begin)->string)
			ft_strdel(&((*begin)->string));
		if ((*begin)->wstring)
		{
			free(&((*begin)->wstring));
			(*begin)->wstring = NULL;
		}
		free(*begin);
		*begin = ptr;
	}
}
