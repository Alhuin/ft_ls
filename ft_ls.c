/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:17:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 23:55:04 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sys/stat.h"
#include "Libft/ft_libft/libft.h"
#include "grp.h"
#include "pwd.h"
#include "time.h"
#include "dirent.h"
#include "stdlib.h"
#include <errno.h>
#include "ft_ls.h"
#include "abr.c"
#include <stdio.h>

void	ft_print_date(char *time, char *str)
{
	int i = 0;
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

char	*ft_get_perms(mode_t mode)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * 11)))
		return (NULL);
	ret[0] = '\0';
	ft_strcat(ret, (S_ISDIR(mode) ? "d" : "-"));
	ft_strcat(ret, ((mode & S_IRUSR) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWUSR) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXUSR) ? "x" : "-"));
	ft_strcat(ret, ((mode & S_IRGRP) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWGRP) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXGRP) ? "x" : "-"));
	ft_strcat(ret, ((mode & S_IROTH) ? "r" : "-"));
	ft_strcat(ret, ((mode & S_IWOTH) ? "w" : "-"));
	ft_strcat(ret, ((mode & S_IXOTH) ? "x" : "-"));
	return (ret);
}

/*
int		ft_printl(char *pref, char *name)
{
	struct stat sb;
	struct group *grp;
	struct passwd *pwd;
	char *time;
	char *path = ft_strjoin(pref, name);

	if (stat(path, &sb) != -1)
	{
		ft_printf("%s", ft_get_perms(sb.st_mode));
		ft_printf("%4ld", sb.st_nlink);
		grp = getgrgid(sb.st_gid);
		pwd = getpwuid(sb.st_uid);
		ft_printf("%9s", pwd->pw_name);
		ft_printf("%9s", grp->gr_name);
		ft_printf("%6lld", sb.st_size);
		time = ctime(&sb.st_mtime);
		ft_print_date(time, "MDH");
		if (S_ISDIR(sb.st_mode))
			ft_printf(" {bcyan}%s{eoc}\n", name);
		else if (ft_strcmp(name, "a.out") == 0)
			ft_printf(" {red}%s{eoc}\n", name);
		else
			ft_printf(" %s\n", name);
	}
	return (0);
}
*/

int main(int argc, char *argv[])
{
	t_arbre *arbre = NULL;
	DIR* rep = NULL;
	struct dirent *fichierLu = NULL;
	char *path;
	int lengh = 0;

	rep = opendir(argc == 1 ? "./" : argv[1]);
	if (rep == NULL)
		exit(-1);
	while ((fichierLu = readdir(rep)) != NULL)
	{
		if ((int)ft_strlen(fichierLu->d_name) > lengh)
			lengh = ft_strlen(fichierLu->d_name);
		if (argc > 1 && ft_strcmp(".", argv[1]) == 0)
			path = ft_strjoin("./", fichierLu->d_name);
		else
			path = ft_strjoin((argc == 1 ? "./" : argv[1]), fichierLu->d_name);
		ft_addnode(fichierLu->d_name, &arbre, path);
	}
	if (closedir(rep) == -1)
		exit(-1);
	ft_print_tree(arbre, 0, lengh + 1);
	ft_printf("\n");
	return 0;
}
/*
int main(int argc, char *argv[])
{
	DIR* rep = NULL;
	struct dirent *fichierLu = NULL;

	rep = opendir(argc == 1 ? "./" : argv[1]);
	if (rep == NULL)
		exit(-1);
	while ((fichierLu = readdir(rep)) != NULL)
		ft_printl(argv[1], fichierLu->d_name);
	if (closedir(rep) == -1)
		exit(-1);

	
	return 0;
}
*/
