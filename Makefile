# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/21 18:36:09 by jjanin-r     #+#   ##    ##    #+#        #
#    Updated: 2018/03/06 12:05:21 by jjanin-r    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: re all clean fclean

NAME = ft_ls

FILES_LS = ft_ls.c tree.c utils.c utils2.c print.c sort.c

PATH_LIBFT = ./Libft/

NAME_LIBFT = $(PATH_LIBFT)libft.a

PATH_LS = ./

INCS = -I $(PATH_LIBFT) -I $(PATH_LS)

SRC_LS = $(addprefix $(PATH_LS), $(FILES_LS))

SRCO_LS = $(SRC_LS:.c=.o)

HEADS = $(PATH_LIBFT)libft.h $(PATH_LS)ft_ls.h

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(NAME_LIBFT) $(SRCO_LS)
	gcc $(FLAGS) $(SRC_LS) -o $(NAME) $(NAME_LIBFT)
	
	@echo "\033[2J"
	@echo "\033[1;93m"
	@echo "            __.----.__"
	@echo "         .-'          \`-."
	@echo "       .'       __       \`."
	@echo "      /     _.-'..\`-._     \\"
	@echo "     /     /  .'  \`.  \     \\"
	@echo "    :     /  /-.  .-\\  \\     :"
	@echo "    |    ;  /   ''   \  :    |"
	@echo "    |    | ;  # || #  | |    |"
	@echo "    |    : |   _/\\_   ; ;    |"
	@echo "    :     \\ \\-'    '-/ /     :"
	@echo "     \\     \\ \\      / /     /"
	@echo "      \`.    \`.=.__.=.'    .'"
	@echo "      / \`.     ''''     .' \\             * ---------------- *"
	@echo "     /    \`-.._/__\_..-'    \\            |      \033[32mft_ls\033[1;93m       |"
	@echo "    /    /      ||      \    \\           |    \033[32mCompiled !\033[1;93m    |"
	@echo "   <.   /       ||       \   .>          * ---------------- *"
	@echo "  |  \`./        ||        \.'  |                  ||"
	@echo "  \`._.'|        ||        |\`._.'                  ||"
	@echo "        | \"'*--.._..--*'\" |                       ||"
	@echo "        | __.._  |  _..__ |                       ||"
	@echo "       .'       \".\"       '.                     \||/"
	@echo "-------------------------------------------------------------------"
	@echo "\033[m"

%.o: %.c $(HEADS)
	gcc $(FLAGS) -o $@ -c $< $(INCS)

$(NAME_LIBFT):
	@make -C $(PATH_LIBFT)

clean:
	@rm -f $(SRCO_LS)
	@make clean -C $(PATH_LIBFT)
	@echo ""
	@echo "\033[1;93m* -------------------- *"
	@echo "|  \033[32mProject cleaned  !\033[1;93m  |"
	@echo "* -------------------- *"
	@echo "\033[m"

fclean: clean
	@rm -f $(NAME) $(NAME_LIBFT)

re: fclean all
