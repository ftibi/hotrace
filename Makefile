NAME = hotrace 

SRC = main.c nodes.c tree.c

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
	

$(SRC)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

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
