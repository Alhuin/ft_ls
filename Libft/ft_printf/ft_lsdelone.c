/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lsdelone.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 21:55:52 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 23:02:37 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_lsdelone(t_param **ptr)
{
	if (!ptr || !*ptr)
		return ;
	if ((*ptr)->string)
		ft_strdel(&((*ptr)->string));
	if ((*ptr)->wstring)
	{
		free(&((*ptr)->wstring));
		(*ptr)->wstring = NULL;
	}
	free(*ptr);
	*ptr = NULL;
}

void	ft_lsdellast(t_param **begin)
{
	t_param	*curr;

	if (!begin || !*begin)
		return ;
	if (!(*begin)->next)
	{
		ft_lsdelone(begin);
		*begin = NULL;
		return ;
	}
	curr = *begin;
	while (curr->next->next)
		curr = curr->next;
	ft_lsdelone(&(curr->next));
	curr->next = NULL;
}
