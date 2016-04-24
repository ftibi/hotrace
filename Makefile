NAME = hotrace

SRC = main.c free_tree.c insert_tree.c search_in_tree.c \
	verbose_tree.c rotate_tree.c depth_of_tree.c\
	ft_strcmp.c ft_putstr.c ft_putendl.c ft_memmove.c\
	ft_memdel.c ft_memcpy.c ft_putchar.c ft_strdel.c ft_strlen.c\
	get_next_line.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strnew.c\
	ft_memalloc.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I. 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)  

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

clean:
	rm -fv $(OBJ)

fclean: clean
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, test

norme:
	norminette $(SRC) hotrace.h

test: $(LIB)
	rm -fv test
	$(CC) -o test  test.c $(CPPFLAGS) 
	./test
