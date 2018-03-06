/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 17:12:36 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 14:56:44 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../ft_libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_param
{
	char			flag;
	char			flag1;
	char			flag2;
	char			flag3;
	char			flag4;
	int				width;
	int				prec;
	int				conv;
	int				size;
	char			type;
	char			*string;
	wchar_t			*wstring;
	wchar_t			wc;
	int				*ptr;
	int				error;
	int				input;
	struct s_param	*next;
}					t_param;

char				*ft_charstr(char c);
int					ft_type(char **str, t_param **begin, va_list ap);
void				ft_mod(t_param **begin, char **str, va_list ap, int i);
char				*ft_uncap(char *str);
char				*ft_longitoa(long long n);
t_param				**ft_lstpush(t_param **begin, t_param *new);
t_param				*ft_inputnode(char **str);
char				*ft_longitoa_base(long long value, int base);
int					ft_printf(const char *restrict format, ...);
int					ft_getparams(const char *restrict format,
					t_param **begin, va_list ap);
t_param				*ft_node(void);
void				ft_compute(t_param **begin);
void				ft_getflags(char **str, t_param **begin);
void				ft_putflag(char c, t_param *ptr);
void				ft_getwidthprec(char **str, t_param **begin, va_list ap);
void				ft_getconv(char **str, t_param **begin);
int					ft_findflag(t_param *ptr, char c);
void				ft_typex(char **str, t_param *ptr, va_list ap);
void				ft_typep(t_param *ptr, va_list ap);
void				ft_typeo(t_param *ptr, va_list ap);
void				ft_types(t_param *ptr, va_list ap);
void				ft_width(t_param *ptr);
int					ft_isflag(t_param *ptr);
void				ft_eraseflag(t_param *ptr, char c);
void				ft_flag0(t_param *ptr, int i, int neg, int esp);
void				ft_doflags(t_param *ptr, int i);
void				ft_flagdiese(t_param *ptr);
char				*ft_strjoinfree(char *s1, char *s2, int i);
void				ft_prec(t_param *ptr);
char				*ft_precstr(t_param *ptr);
char				*ft_ulongitoa_base(unsigned long long value, int base);
void				ft_typed(t_param *ptr, va_list ap);
char				*ft_ulongitoa(unsigned long long n);
void				ft_typeu(t_param *ptr, va_list ap);
void				ft_typec(t_param *ptr, va_list ap);
void				ft_u(t_param *ptr, va_list ap);
void				ft_bigu(t_param *ptr, va_list ap);
void				ft_lsdel(t_param **begin);
int					ft_putwchar(wchar_t c);
int					ft_error(char *str, t_param **begin);
void				ft_lsdelone(t_param **begin);
void				ft_lsdellast(t_param **begin);
int					ft_print(t_param *ptr, int ret);
void				ft_replaceflag(t_param *ptr, char c, char d);
void				ft_whichconv(int i, char **str, t_param *ptr);
int					ft_putwstr(wchar_t *str);
void				ft_bigs(t_param *ptr, va_list ap);
int					ft_wstrlen(wchar_t *s);
wchar_t				*ft_wstrndup(wchar_t *wstr, int len);
void				ft_wprec(t_param *ptr);
int					ft_wclen(wchar_t wc);
void				ft_getwstring(t_param *ptr);
void				ft_doflags2(t_param *ptr, int i);
void				ft_getmod(t_param **begin, char **str, va_list ap,
					char *ptr);
void				ft_input(t_param **begin, char **str, int i, char *ptr);
void				ft_compute1(t_param *ptr);
void				ft_flag01(t_param *ptr, int neg, int esp);
char				*ft_printwidth(t_param *ptr, char c);
char				*ft_dtoa(double nbr, int prec);
void				ft_typef(t_param *ptr, va_list ap);
void				ft_bigc(t_param *ptr, va_list ap);
int					ft_checkerror(t_param **begin);
char				*ft_color(char *str);
int					ft_colorlen(char *str);
void				ft_nomod(t_param **begin, char **str, int i, char *ptr);

#endif
