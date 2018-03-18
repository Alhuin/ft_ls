# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/12 15:43:27 by jmonneri     #+#   ##    ##    #+#        #
#    Updated: 2018/03/18 16:06:19 by jjanin-r    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_ls
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_OBJ = ./objs/
PATH_SRC = ./srcs/
PATH_INC = ./incs/
INC = $(addprefix $(PATH_INC), ft_ls.h)

#******************************************************************************#
#                                     LIBFT                                    #
#******************************************************************************#

PATH_LIBFT = ./Libft/
NAME_LIBFT = libft.a
LIBFT = $(PATH_LIBFT)$(NAME_LIBFT)

#******************************************************************************#
#                                     FT_LS                                    #
#******************************************************************************#

PATH_SRC_FT_LS = $(PATH_SRC)Ls/
PATH_OBJ_FT_LS = $(PATH_OBJ)Ls/
FILES_FT_LS = ft_ls parse print sort tree utils utils2 utils3
OBJ_FT_LS = $(addprefix $(PATH_OBJ_FT_LS), $(addsuffix .o, $(FILES_FT_LS)))
SRC_FT_LS = $(addprefix $(PATH_SRC_FT_LS), $(addsuffix .c, $(FILES_FT_LS)))

#******************************************************************************#
#                                      ALL                                     #
#******************************************************************************#

PATHS_OBJ = $(PATH_OBJ) $(PATH_OBJ_FT_LS)
OBJ = $(OBJ_FT_LS)
SRC = $(SRC_FT_LS)
FILES = $(FILES_FT_LS)

#******************************************************************************#
#                                     RULES                                    #
#******************************************************************************#

all: $(NAME)

$(NAME): $(LIBFT) $(PATHS_OBJ) $(OBJ_FT_LS)
	@$(CC) $(CC_FLAGS) $(OBJ) -L $(PATH_LIBFT) -l ft -o $(NAME)
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

$(PATH_OBJ_FT_LS)%.o: $(PATH_SRC_FT_LS)%.c $(INC)
	@printf %b "Compiling $@...                                             \r"
	@$(CC) $(CC_FLAGS) -o $@ -c $<
	@printf %b "                                                            \r"

$(LIBFT):
	@make -C $(PATH_LIBFT)

$(PATHS_OBJ):
	@mkdir $@

clean:
	@rm -rf $(PATH_OBJ)
	@make clean -C $(PATH_LIBFT)

fclean:
	@rm -f $(NAME)
	@rm -rf $(PATH_OBJ)
	@make fclean -C $(PATH_LIBFT)

re: fclean all
