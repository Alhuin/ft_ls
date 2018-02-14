# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/21 18:36:09 by jjanin-r     #+#   ##    ##    #+#        #
#    Updated: 2018/02/13 14:53:41 by jjanin-r    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: re all clean fclean

NAME = libft.a

NAME_PRINTF = libftprintf.a

FILES_PRINTF = ft_printf.c ft_inputnode.c ft_charstr.c ft_getparams.c\
			   ft_longitoa.c ft_longitoa_base.c ft_lstpush.c ft_mod.c\
			   ft_type.c ft_uncap.c ft_node.c ft_compute.c ft_getflags.c\
			   ft_putflag.c ft_getwidthprec.c ft_getconv.c ft_doflags.c\
			   ft_findflag.c ft_typex.c ft_typep.c ft_typeo.c ft_types.c\
			   ft_width.c ft_isflag.c ft_eraseflag.c ft_flag0.c ft_flagdiese.c\
			   ft_strjoinfree.c ft_prec.c ft_precstr.c ft_ulongitoa_base.c\
			   ft_typed.c ft_ulongitoa.c ft_typeu.c ft_typec.c ft_u.c\
			   ft_bigu.c ft_lsdel.c ft_putwchar.c ft_lsdelone.c\
			   ft_print.c ft_replaceflag.c ft_whichconv.c ft_putwstr.c\
			   ft_wstrlen.c ft_wstrndup.c ft_wprec.c ft_wclen.c\
			   ft_getmod.c ft_input.c ft_printwidth.c\
			   ft_dtoa.c ft_typef.c unicode.c ft_checkerror.c color.c\

FILES_LIBFT = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
			  ft_strncat.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
			  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c\
			  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
			  ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
			  ft_memchr.c ft_memcmp.c ft_memmove.c ft_putchar.c ft_putstr.c\
			  ft_putendl.c ft_putnbr.c ft_strnew.c ft_strdel.c ft_memdel.c\
			  ft_strclr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			  ft_putnbr_fd.c ft_memalloc.c ft_striter.c ft_striteri.c\
			  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
			  ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_lstnew.c\
			  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
			  ft_int_swap.c ft_gswap.c ft_intlen.c ft_print_strlst.c\
			  ft_putstr2d.c get_next_line.c ft_itoa_base.c\

PATH_PRINTF = ./ft_printf/

PATH_LIBFT = ./ft_libft/

SRC_PRINTF = $(addprefix $(PATH_PRINTF), $(FILES_PRINTF))

SRC_LIBFT = $(addprefix $(PATH_LIBFT), $(FILES_LIBFT))

SRCO_PRINTF = $(SRC_PRINTF:.c=.o)

SRCO_LIBFT = $(SRC_LIBFT:.c=.o)

HEADS = $(PATH_PRINTF)libftprintf.h $(PATH_LIBFT)libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCO_PRINTF) $(SRCO_LIBFT)
	ar rcs $(NAME) $(SRCO_PRINTF) $(SRCO_LIBFT)

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@ -I $(PATH_PRINTF) -I $(PATH_LIBFT)

clean:
	rm -f $(SRCO_PRINTF) $(SRCO_LIBFT)

fclean: clean
	rm -f $(NAME) $(PATH_LIBFT)$(NAME)

re: fclean all
