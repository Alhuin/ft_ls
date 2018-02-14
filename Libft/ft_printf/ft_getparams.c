/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getparams.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 15:21:15 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 22:20:35 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_getparams(const char *restrict format, t_param **begin, va_list ap)
{
	int		i;
	char	*str;
	int		clen;

	i = 0;
	str = ft_strdup(format);
	clen = ft_colorlen(str);
	str = ft_color(str);
	if ((ft_strchr(str, '%')) == NULL)
		ft_nomod(begin, &str, ft_strlen(str), str);
	else
		ft_mod(begin, &str, ap, 0);
	ft_strdel(&str);
	return (clen);
}
