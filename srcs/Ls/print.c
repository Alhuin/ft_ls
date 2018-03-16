/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:00:54 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 15:39:23 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_print_name(t_tree *tree, int lengh, t_flags *flags)
{
	if (flags->l != 1 || flags->un == 1)
	{
		if (tree->file->name[0] != '.' || flags->a == 1)
		{
			if (S_ISLNK(tree->file->sb.st_mode))
				ft_printf("{magenta}%-*s {eoc}", lengh, tree->file->name);
			else if (S_ISDIR(tree->file->sb.st_mode))
				ft_printf("{bcyan}%-*s {eoc}", lengh, tree->file->name);
			else if (tree->file->sb.st_mode & S_IXUSR)
				ft_printf("{red}%-*s {eoc}", lengh, tree->file->name);
			else
				ft_printf("%-*s ", lengh, tree->file->name);
			if (flags->un == 1)
				ft_printf("\n");
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

static int			ft_print_date(time_t t)
{
	char	*date;
	char	*m;
	char	*d;
	char	*h;
	time_t	now;

	now = time(NULL);
	date = ctime(&(t));
	h = ft_strsub(date, 11, 5);
	d = ft_strsub(date, 8, 2);
	m = ft_strsub(date, 4, 3);
	if (!h || !d || !m)
		return (-1);
	ft_printf("%3s", d);
	ft_strdel(&d);
	ft_printf("%4s", ft_uncap(m));
	ft_strdel(&m);
	if (now - t >= 15778476 || now - t <= -3600)
	{
		d = ft_strsub(date, 20, 4);
		ft_printf("%6s", d);
		ft_strdel(&d);
	}
	else
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

int					ft_print_minmaj(t_file *file)
{
	ft_printf("%4d,%5d", major(file->sb.st_rdev), minor(file->sb.st_rdev));
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
		ft_printf("%10s", (pw ? pw : pwd->pw_name));
		ft_strdel(&pw);
		ft_printf("  %10s", grp->gr_name);
		((*file)->sb.st_rdev != 0 ? ft_print_minmaj(*file) :
			ft_printf("%7lld", (*file)->sb.st_size));
		if (ft_print_date((*file)->sb.st_mtime) == -1)
			return (-1);
		ft_printl_name(file);
	}
	return (0);
}