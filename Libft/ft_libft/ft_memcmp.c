/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 16:27:02 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 16:27:02 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s01;
	unsigned char	*s02;

	s02 = (unsigned char *)s2;
	s01 = (unsigned char *)s1;
	while (n > 0)
	{
		if (*s01 != *s02)
			return ((unsigned char)*s01 - (unsigned char)*s02);
		s01++;
		s02++;
		n--;
	}
	return (0);
}
