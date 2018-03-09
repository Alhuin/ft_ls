/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:00:54 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:07:34 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_name(t_tree *tree, int lengh, t_flags *flags)
{
	if (flags->l != 1)
	{
		if (tree->file->name[0] != '.' || flags->a == 1)
		{
			if (S_ISLNK(tree->file->sb.st_mode))
				ft_printf("{magenta}%-*s{eoc}", lengh, tree->file->name);
			else if (S_ISDIR(tree->file->sb.st_mode))
				ft_printf("{bcyan}%-*s{eoc}", lengh, tree->file->name);
			else if (tree->file->sb.st_mode & S_IXUSR)
				ft_printf("{red}%-*s{eoc}", lengh, tree->file->name);
			else
				ft_printf("%-*s", lengh, tree->file->name);
		}
	}
	else
		ft_printl(&(tree->file),  &flags);
}

void		ft_print_tree(t_tree *tree, int lengh, t_flags *flags)
{
	if (tree != NULL)
	{
		if (tree->left)
			ft_print_tree(tree->left, lengh, flags);
		if (tree->file->alphatime == NULL)
			ft_print_name(tree, lengh, flags);
		else
			ft_print_tree(tree->file->alphatime, lengh, flags);
		if (tree->right)
			ft_print_tree(tree->right, lengh, flags);
	}
}

void		ft_print_date(char *time, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'M')
			ft_printf("%4.3s", time + 4);
		if (str[i] == 'D')
			ft_printf("%3.2s", time + 8);
		if (str[i] == 'H')
			ft_printf("%6.5s", time + 11);
		i++;
	}
}

int			ft_printl(t_file **file, t_flags **flags)
{
	struct group	*grp;
	struct passwd	*pwd;
	char			*time;

	if ((*file)->name[0] != '.' || (*flags)->a == 1)
	{
		ft_printf("%s", ft_get_perms((*file)->sb.st_mode));
		ft_printf("%3ld", (*file)->sb.st_nlink);
		grp = getgrgid((*file)->sb.st_gid);
		pwd = getpwuid((*file)->sb.st_uid);
		ft_printf("%7s", pwd->pw_name);
		ft_printf("%9s", grp->gr_name);
		ft_printf("%8lld", (*file)->sb.st_size);
		time = ctime(&(*file)->sb.st_mtime);
		ft_print_date(time, "MDH");
		if (S_ISDIR((*file)->sb.st_mode))
			ft_printf(" {bcyan}%s{eoc}\n", (*file)->name);
		else if ((*file)->sb.st_mode & S_IXUSR)
			ft_printf(" {red}%s{eoc}\n", (*file)->name);
		else
			ft_printf(" %s\n", (*file)->name);
	}
	return (0);
}
