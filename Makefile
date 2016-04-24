NAME = hotrace

SRC = main.c free_tree.c alloc_tree.c search_in_tree.c \
	verbose_tree.c rotate_tree.c depth_of_tree.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I. -I./libft/includes

all: $(LIB) $(NAME)

$(LIB):
	make -C ./libft
	cp $(LIB) libft.a

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)  libft.a


%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

clean:
	make clean -C ./libft
	rm -fv $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -fv $(NAME) libft.a

re: fclean all

.PHONY: all, clean, fclean, re, test

norme:
	norminette $(SRC) hotrace.h

test: $(LIB)
	rm -fv test
	$(CC) -o test  test.c $(CPPFLAGS)  libft.a
	./test
