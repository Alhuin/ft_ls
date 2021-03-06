/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:00:54 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/18 16:12:16 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/ft_ls.h"

void				ft_print_name(t_tree *tree, t_flags *flags)
{
	if (flags->l != 1 || flags->un == 1)
	{
		if (tree->file->name[0] != '.' || flags->a == 1 ||
				ft_strncmp(tree->file->name, "../", 3) == 0)
		{
			if (S_ISLNK(tree->file->sb.st_mode))
				ft_printf("{magenta}%-10s {eoc}", tree->file->name);
			else if (S_ISDIR(tree->file->sb.st_mode))
				ft_printf("{bcyan}%-10s {eoc}", tree->file->name);
			else if (tree->file->sb.st_mode & S_IXUSR)
				ft_printf("{red}%-10s {eoc}", tree->file->name);
			else
				ft_printf("%-10s ", tree->file->name);
			if (flags->un == 1)
				ft_printf("\n");
		}
	}
	else
		ft_printl(&(tree->file), &flags);
}

void				ft_print_tree(t_tree *tree, t_flags *flags)
{
	if (tree != NULL)
	{
		if (tree->left)
			ft_print_tree(tree->left, flags);
		ft_print_name(tree, flags);
		if (tree->right)
			ft_print_tree(tree->right, flags);
	}
}

static int			ft_print_date(time_t t)
{
	char	*m;
	char	*d;
	char	*h;
	time_t	now;

	now = time(NULL);
	h = ft_strsub(ctime(&(t)), 11, 5);
	d = ft_strsub(ctime(&(t)), 8, 2);
	m = ft_strsub(ctime(&(t)), 4, 3);
	if (!h || !d || !m)
		return (-1);
	ft_printf("%4s", m);
	ft_strdel(&m);
	ft_printf("%3s", d);
	ft_strdel(&d);
	if (now - t >= 15778476 || now - t <= -3600)
	{
		d = ft_strsub(ctime(&(t)), 20, 4);
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

int					ft_printl(t_file **file, t_flags **flags)
{
	struct group	*grp;
	struct passwd	*pwd;
	char			*pw;
	char			*perms;

	pw = NULL;
	perms = NULL;
	if ((*file)->name[0] != '.' || (*flags)->a == 1 ||
			ft_strncmp((*file)->name, "../", 3) == 0)
	{
		ft_printperms(perms, file);
		grp = getgrgid((*file)->sb.st_gid);
		if (!(pwd = getpwuid((*file)->sb.st_uid)))
			pw = ft_itoa((*file)->sb.st_uid);
		ft_printf("%10s", (pw ? pw : pwd->pw_name));
		ft_strdel(&pw);
		ft_printf("  %10s", grp->gr_name);
		((*file)->sb.st_rdev != 0 ? ft_print_minmaj(*file) :
			ft_printf("%7lld", (*file)->sb.st_size));
		if (ft_print_date(((*flags)->u == 1 ? (*file)->sb.st_atime :
						(*file)->sb.st_mtime)) == -1)
			return (-1);
		ft_printl_name(file);
	}
	return (0);
}
