/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_input.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 03:14:33 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 22:19:44 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_input(t_param **begin, char **str, int i, char *ptr)
{
	char	*tmp;
	t_param	*new;

	tmp = ft_strsub(*str, 0, i);
	if ((new = ft_inputnode(&tmp)) == NULL)
	{
		ft_lsdel(begin);
		ft_strdel(&ptr);
		exit(-1);
	}
	ft_lstpush(begin, new);
	*str = *str + i;
}

void	ft_nomod(t_param **begin, char **str, int i, char *ptr)
{
	char	*tmp;
	t_param	*new;

	tmp = ft_strsub(*str, 0, i);
	if ((new = ft_inputnode(&tmp)) == NULL)
	{
		ft_lsdel(begin);
		ft_strdel(&ptr);
		exit(-1);
	}
	ft_lstpush(begin, new);
}
