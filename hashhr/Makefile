# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/24 00:56:34 by tguillot          #+#    #+#              #
#    Updated: 2016/04/24 16:29:19 by tbeauman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

FLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = includes/

SRCS_NAME = main.c\
			ft_bzero.c\
			ft_memset.c\
			ft_strcpy.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlen.c\
			ft_strnew.c\
			ft_strsub.c\
			get_next_line.c\
			ft_hachage.c\
			ft_putchar.c\
			ft_putendl.c\
			ft_putstr.c\
			ft_strcmp.c\
			ft_tab_init.c\
			ft_stock_data.c\
			ft_putnbr.c\
			ft_putnbrdl.c\
			ft_iterative_power.c\
			ft_search.c\
			search_in_tree.c\
			rotate_tree.c\
			insert_tree.c\
			depth_of_tree.c\
			free_tree.c\
			ft_strdel.c\
			ft_memdel.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS_PATH = objs/

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

all: odir $(NAME)

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(FLAGS) $(OBJS)
	@echo "\033[32;4mExecutable Hotrace created!\033[0m"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo "\033[34;1mCompiling...\033[0m"
	@gcc $(FLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

clean:
	@echo "\033[33mCleaning objects...\033[0m"
	@rm -rf $(OBJS_PATH)
	@echo "\033[32;4mDone.\033[0m"

fclean: clean
	@echo "\033[33mCleaning binary...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32;4mDone.\033[0m"

re: fclean all

odir:
	@mkdir -p objs/

.PHONY: clean fclean re odir
