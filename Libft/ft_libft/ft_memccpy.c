/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 16:27:01 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 16:27:01 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	unsigned char	c_cpy;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	c_cpy = (unsigned char)c;
	while (i < n)
	{
		*d = *s;
		if (*s == c_cpy)
			return ((unsigned char*)dst + i + 1);
		d++;
		s++;
		i++;
	}
	return (NULL);
}
