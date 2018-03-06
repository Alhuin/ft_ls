/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flagdiese.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 22:19:51 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 00:53:32 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_flagdiese(t_param *ptr)
{
	if (ptr->string && ptr->string[0])
	{
		if (ptr->type == 'o' || ptr->type == 'O')
			if (ft_atoi(ptr->string) != 0)
				ptr->string = ft_strjoin("0", ptr->string);
		if (ptr->type == 'x' || ptr->type == 'X')
		{
			if (ft_strcmp(ptr->string, "0") != 0)
			{
				if (ptr->type == 'x')
					ptr->string = ft_strjoinfree("0x", ptr->string, 2);
				else
					ptr->string = ft_strjoinfree("0X", ptr->string, 2);
			}
		}
	}
}
