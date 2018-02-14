/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 17:56:40 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 20:36:21 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_put(unsigned int wc)
{
	return (write(1, &wc, 1));
}

int			ft_putwchar(wchar_t c)
{
	int ret;

	ret = 0;
	if (c <= 127)
		ret += ft_put(c);
	else if (c <= 2047)
	{
		ret += ft_put(0xC0 | (c >> 6));
		ret += ft_put(0x80 | (0x3F & c));
	}
	else if (c <= 65535)
	{
		ret += ft_put(0xE0 | (c >> 12));
		ret += ft_put(0x80 | (0x3F & c >> 6));
		ret += ft_put(0x80 | (0x3F & c));
	}
	else if (c <= 1114111)
	{
		ret += ft_put(0xF0 | (c >> 18));
		ret += ft_put(0x80 | (0x3F & c >> 12));
		ret += ft_put(0x80 | (0x3F & c >> 6));
		ret += ft_put(0x80 | (0x3F & c));
	}
	return (ret);
}
