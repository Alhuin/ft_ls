/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_strlst.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 16:27:04 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 16:27:04 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_strlst(t_list **alst)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = *alst;
	while (ptr != NULL)
	{
		if (i == 0)
			ft_putstr("Begin list\n");
		ft_putstr("\nmaillon ");
		ft_putnbr(i);
		ft_putstr("\ncontent : ");
		ft_putstr(ptr->content);
		ft_putstr("\nsize : ");
		ft_putnbr(ptr->content_size);
		ft_putchar('\n');
		i++;
		ptr = ptr->next;
	}
	ft_putstr("\nEnd list");
}
