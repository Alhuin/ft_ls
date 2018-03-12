/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:00:54 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 14:06:10 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_print_name(t_tree *tree, int lengh, t_flags *flags)
{
	(void)lengh;
	if (flags->l != 1)
	{
		if (tree->file->name[0] != '.' || flags->a == 1)
		{
			if (S_ISLNK(tree->file->sb.st_mode))
				ft_printf("{magenta}%s {eoc}", tree->file->name);
			else if (S_ISDIR(tree->file->sb.st_mode))
				ft_printf("{bcyan}%s {eoc}", tree->file->name);
			else if (tree->file->sb.st_mode & S_IXUSR)
				ft_printf("{red}%s {eoc}", tree->file->name);
			else
				ft_printf("%s ", tree->file->name);
		}
	}
	else
		ft_printl(&(tree->file), &flags);
}

void				ft_print_tree(t_tree *tree, int lengh, t_flags *flags)
{
	if (tree != NULL)
	{
		if (tree->left)
			ft_print_tree(tree->left, lengh, flags);
		ft_print_name(tree, lengh, flags);
		if (tree->right)
			ft_print_tree(tree->right, lengh, flags);
	}
}

static int			ft_print_date(char *time)
{
	char *m;
	char *d;
	char *h;

	h = ft_strsub(time, 11, 5);
	d = ft_strsub(time, 8, 2);
	m = ft_strsub(time, 4, 3);
	if (!h || !d || !m)
		return (-1);
	ft_printf("%3s", d);
	ft_strdel(&d);
	ft_printf("%4s", ft_uncap(m));
	ft_strdel(&m);
	ft_printf("%6s", h);
	ft_strdel(&h);
	return (0);
}

static int			ft_printl_name(t_file **file)
{
	char buf[1024];

	if (S_ISLNK((*file)->sb.st_mode))
	{
		ft_bzero(buf, 1024);
		if (readlink((*file)->path, buf, 1024) == -1)
			return (-1);
		ft_printf(" {magenta}%s{eoc} -> %s\n", (*file)->name, buf);
	}
	else if (S_ISDIR((*file)->sb.st_mode))
		ft_printf(" {bcyan}%s{eoc}\n", (*file)->name);
	else if ((*file)->sb.st_mode & S_IXUSR)
		ft_printf(" {red}%s{eoc}\n", (*file)->name);
	else
		ft_printf(" %s\n", (*file)->name);
	return (0);
}

int					ft_printl(t_file **file, t_flags **flags)
{
	struct group	*grp;
	struct passwd	*pwd;
	char			*pw;
	char			*perms;

	pw = NULL;
	if ((*file)->name[0] != '.' || (*flags)->a == 1)
	{
		perms = ft_get_perms((*file)->sb.st_mode);
		ft_printf("%s", perms);
		ft_strdel(&perms);
		ft_printf("%3ld", (*file)->sb.st_nlink);
		grp = getgrgid((*file)->sb.st_gid);
		if (!(pwd = getpwuid((*file)->sb.st_uid)))
			pw = ft_itoa((*file)->sb.st_uid);
		ft_printf("%7s", (pw ? pw : pwd->pw_name));
		ft_strdel(&pw);
		ft_printf("  %s", grp->gr_name);
		ft_printf("%7lld", (*file)->sb.st_size);
		if (ft_print_date(ctime(&(*file)->sb.st_mtime)) == -1)
			return (-1);
		ft_printl_name(file);
	}
	return (0);
}
