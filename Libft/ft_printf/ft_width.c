/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_width.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 16:41:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 08:17:03 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_width(t_param *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ptr->next)
		ptr = ptr->next;
	if (ptr->type == 'p')
	{
		ptr->string = ft_strjoinfree("0x", ptr->string, 2);
		ptr->type = 'a';
	}
	if ((i = ptr->width - ft_strlen(ptr->string)) > 0)
	{
		if (ft_isflag(ptr) == 1)
			ft_doflags(ptr, i);
		else
			while (i-- > 0)
			{
				if (ptr->type == '%' && ft_findflag(ptr, 'O') != -1)
					ptr->string = ft_strjoinfree("0", ptr->string, 2);
				else
					ptr->string = ft_strjoinfree(" ", ptr->string, 2);
			}
	}
}
