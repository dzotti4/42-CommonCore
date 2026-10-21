NAME = fractol

SRCS = main.c handle.c julia.c mandelbrot.c render.c ft_atof.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux
INCLUDES = -I$(LIBFT_DIR) -I. -I$(MLX_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR)
LIBMLX = -lmlx -lm -lX11 -lXext
RM = rm -f

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(LDFLAGS) $(LIBMLX) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
