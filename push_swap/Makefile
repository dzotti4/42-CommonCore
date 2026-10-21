NAME = push_swap

SRC = main.c stack_utils.c safe_atoi.c parse_arg.c operation_swap.c operation_push.c operation_rotate.c operation_reverse_rotate.c stack_check.c sort_small.c sort_big.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

DEPS = push_swap.h
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
