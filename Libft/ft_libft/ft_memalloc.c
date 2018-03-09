/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 16:27:00 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 16:27:00 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *m;

	if (!(m = malloc(sizeof(size_t) * size)))
		return (NULL);
	while (size > 0)
		m[--size] = 0;
	return ((void *)m);
}
