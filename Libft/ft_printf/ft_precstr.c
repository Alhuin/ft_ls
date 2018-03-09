/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_precstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:11:22 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/13 20:27:11 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_precstr(t_param *ptr)
{
	int		i;
	char	*ret;

	i = 0;
	if (ptr->prec == -1)
		ptr->prec = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ptr->prec + 1))))
		return (NULL);
	ret[ptr->prec] = '\0';
	while (ptr->prec-- > 0)
	{
		ret[i] = ptr->string[i];
		i++;
	}
	return (ret);
}
