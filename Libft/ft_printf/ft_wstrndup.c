/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrndup.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 18:23:57 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 02:11:34 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_wlen(wchar_t *wstr, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		if (wstr[i] <= 127)
			len--;
		else if (wstr[i] <= 2047)
			len -= 2;
		else if (wstr[i] <= 65535)
			len -= 3;
		else if (wstr[i] <= 1114111)
			len -= 4;
		if (len >= 0)
			i++;
	}
	return (i);
}

wchar_t		*ft_wstrndup(wchar_t *wstr, int len)
{
	wchar_t	*ret;
	int		i;

	i = 0;
	ret = NULL;
	len = ft_wlen(wstr, len);
	if (len < ft_wstrlen(wstr))
	{
		if (!(ret = (wchar_t *)malloc(sizeof(wchar_t) * len + 1)))
			return (NULL);
		ret[len] = '\0';
		while (len-- > 0)
		{
			ret[i] = wstr[i];
			i++;
		}
		return (ret);
	}
	return (wstr);
}
