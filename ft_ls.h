/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:30 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 23:41:18 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "Libft/ft_libft/libft.h"
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>

typedef struct		file
{
	struct stat		*sb;
	int				exec;
	int				dir;
	int				hidden;
	char			*permissions;
}					t_file;

typedef struct		arbre
{
	char			*path;
	char			*name;
	struct arbre	*left;
	struct arbre	*right;
	t_file			*file;
}					t_arbre;

char				*ft_get_permissions(mode_t mode, t_arbre **arbre);
int					ft_get_stats(char *name, t_arbre **arbre, char *path);
int					ft_createnode(char *name, t_arbre **tocreate, char *path);
int					ft_addnode(char *name, t_arbre **node, char *path);
void				ft_print_name(t_arbre *arbre, int type, int lengh);
void				ft_print_tree(t_arbre *arbre, int type, int lengh);
void				ft_rev_print_tree(t_arbre *arbre, int type, int lengh);
int					ft_addnode(char *name, t_arbre **node, char *path);
# endif
