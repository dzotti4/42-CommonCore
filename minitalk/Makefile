NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Ift_printf

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_CLIENT) libft/libft.a ft_printf/libftprintf.a -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_SERVER) libft/libft.a ft_printf/libftprintf.a -o $(NAME_SERVER)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all
