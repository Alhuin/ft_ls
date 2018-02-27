/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:30 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 18:15:10 by jjanin-r    ###    #+. /#+    ###.fr     */
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

typedef struct		s_tree
{
	struct s_file	*file;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_file
{
	struct stat		sb;
	int				arg;
	int				exec;
	int				total;
	char			*name;
	char			*path;
	t_tree			*subtree;
	t_tree			*alphatime;
}					t_file;

typedef struct		s_flags
{
	int				l;
	int				a;
	int				r;
	int				R;
	int				t;
}					t_flags;

char				*ft_get_permissions(mode_t mode, t_tree **tree);
int					ft_get_stats(char *name, t_tree **tree, char *path);
int					ft_createnode(t_file **file, t_tree **tocreate);
int					ft_addnode(t_file **file, t_tree **node);
int					ft_raddnode(t_file **file, t_tree **node);
int					ft_taddnode(t_file **file, t_tree **node);
int					ft_traddnode(t_file **file, t_tree **node);
void				ft_print_name(t_tree *tree, int lengh, t_flags *flags);
void				ft_print_tree(t_tree *tree, int lengh, t_flags *flags);
void				ft_rev_print_tree(t_tree *tree, int lengh, t_flags *flags);
int					ft_racnode(char *name, t_tree **tocreate, char *path);
void				ft_computeargs(t_tree *tree, t_flags **flags);
int					ft_printl(t_file **file, t_flags **flags);
int					ft_getdirstats(t_file **file, char *arg, t_flags *flags);
void				ft_revputeargs(t_tree *tree, t_flags **flags);
# endif
