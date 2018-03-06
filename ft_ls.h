/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:30 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 15:43:00 by jjanin-r    ###    #+. /#+    ###.fr     */
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
	int				arg;
	int				l;
	int				a;
	int				r;
	int				bigr;
	int				t;
}					t_flags;

char				*ft_buildpath(char *arg, char *name);
char				*ft_get_perms(mode_t mode);
int					ft_getdirstats(t_file **file, char *arg, t_flags *flags);
int					ft_createnode(t_file **file, t_tree **tocreate);
int					ft_addnode(t_file **file, t_tree **node);
int					ft_raddnode(t_file **file, t_tree **node);
int					ft_taddnode(t_file **file, t_tree **node);
int					ft_traddnode(t_file **file, t_tree **node);
int					ft_fill_tree(t_file **file, t_tree **tree, t_flags *flags);
void				ft_print_name(t_tree *tree, int lengh, t_flags *flags);
void				ft_print_tree(t_tree *tree, int lengh, t_flags *flags);
void				ft_computeargs(t_tree *tree, t_flags **flags);
int					ft_printl(t_file **file, t_flags **flags);
void				ft_free_node(t_tree **node);
void				ft_free_tree(t_tree **tree);
void				ft_last_free(t_tree *tree, t_file *file, t_flags *flags);
void				ft_compute_rargs(t_tree *tree, t_flags **flags);
#endif
