/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/18 16:05:40 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/18 16:17:46 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_ls.h"

int			atime_sort(t_file *to_sort, t_file *node)
{
	if (to_sort->sb.st_atimespec.tv_sec == node->sb.st_atimespec.tv_sec)
		return (node->sb.st_atimespec.tv_nsec -
				to_sort->sb.st_atimespec.tv_nsec);
	else
		return (node->sb.st_atimespec.tv_sec -
				to_sort->sb.st_atimespec.tv_sec);
}

int			ft_print_minmaj(t_file *file)
{
	ft_printf("%4d,%5d", major(file->sb.st_rdev), minor(file->sb.st_rdev));
	return (0);
}

void		ft_printperms(char *perms, t_file **file)
{
	perms = ft_get_perms((*file)->sb.st_mode);
	ft_printf("%s", perms);
	ft_strdel(&perms);
	ft_printf("%3ld", (*file)->sb.st_nlink);
}

char		*ft_firstperm(char *ret, mode_t mode)
{
	if (S_ISLNK(mode))
		ft_strcat(ret, "l");
	else if (S_ISCHR(mode))
		ft_strcat(ret, "c");
	else if (S_ISBLK(mode))
		ft_strcat(ret, "b");
	else if (S_ISFIFO(mode))
		ft_strcat(ret, "p");
	else
		ft_strcat(ret, (S_ISDIR(mode) ? "d" : "-"));
	return (ret);
}
