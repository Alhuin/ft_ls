/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 13:47:30 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/18 16:38:51 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../Libft/ft_libft/libft.h"
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
	char			*error;
	int				total;
	char			*name;
	char			*path;
	t_tree			*subtree;
}					t_file;

typedef struct		s_flags
{
	int				arg;
	int				elem;
	int				un;
	int				help;
	int				f;
	int				d;
	int				u;
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
int					ft_fill_tree(t_file **file, t_tree **tree, t_flags *flags,
						int errors);
void				ft_print_name(t_tree *tree, t_flags *flags);
void				ft_print_tree(t_tree *tree, t_flags *flags);
void				ft_computeargs(t_tree *tree, t_flags **flags);
int					ft_printl(t_file **file, t_flags **flags);
void				ft_free_node(t_tree **node);
void				ft_free_tree(t_tree **tree);
void				ft_last_free(t_tree *tree, t_file *file, t_flags *flags);
int					ascii_sort(t_file *to_sort, t_file *node);
int					err_sort(t_file *to_sort, t_file *node);
int					mtime_sort(t_file *to_sort, t_file *node);
int					atime_sort(t_file *to_sort, t_file *node);
int					ft_sort(t_file **file, t_tree **node, int(*fn)());
int					rev_ascii_sort(t_file *to_sort, t_file *node);
int					ft_double_sort(t_file **file, t_tree **node, int(*f1)(),
						int(*f2)());
int					rev_time_sort(t_file *to_sort, t_file *node);
void				ft_print_errors(t_tree *tree, t_flags *flags);
void				ft_print_name(t_tree *tree, t_flags *flags);
int					ft_init_flags(t_flags **flags);
int					ft_init_file(t_file **file, int i,
						char *arg);
void				ft_getfilestats(t_file **file, t_tree **errors,
						t_tree **tree, t_flags *flags);
char				*ft_uncap(char *str);
int					ft_error(t_file *file, char *error, t_flags *flags);
int					ft_print_help(t_flags **flags);
int					ft_checkflag(char c, t_flags **flags);
int					ft_print_minmaj(t_file *file);
void				ft_recursive(t_tree *tree, t_flags **flags);
int					atime_sort(t_file *to_sort, t_file *node);
void				ft_addnode(t_file **file, t_tree **tree);
void				ft_printperms(char *perms, t_file **file);
char				*ft_firstperm(char *ret, mode_t mode);
#endif
