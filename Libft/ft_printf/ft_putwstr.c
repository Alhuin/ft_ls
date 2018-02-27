/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 18:28:37 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 18:28:45 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putwstr(wchar_t *str)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			ret += ft_putwchar(str[i]);
			i++;
		}
	}
	return (ret);
}
