NAME = fillit
CC = gcc -Wall -Wextra -Werror
SRC = ft_check_block.c \
	  ft_check_map.c \
	  ft_check_tetrimon.c \
	  ft_open_file.c \
	  ft_position.c \
	  ft_show_error.c \
	  ft_solve.c \
	  ft_swap.c \
	  main.c 

OBJ =	$(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

%.o: %.c
		$(CC) -c -o $@ $<

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: clean
