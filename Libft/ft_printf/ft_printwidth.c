/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printwidth.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 06:58:42 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 07:15:50 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printwidth(t_param *ptr, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	if (c == 'W')
		i = ptr->width - ft_wclen(ptr->wc);
	else if (c == 'w')
		i = ptr->width - 1;
	else if (c == 'S')
		i = ptr->width - ft_wstrlen(ptr->wstring);
	if (i > 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * i + 1)))
			return (NULL);
		if (ft_findflag(ptr, '0') != -1 || ft_findflag(ptr, 'O') != -1)
			while (str[j])
				str[j++] = '0';
		else
			while (str[j])
				str[j++] = ' ';
	}
	return (str);
}
