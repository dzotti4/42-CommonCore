NAME = philo

SRC = utils.c time.c forks.c actions.c stop.c monitor.c clean_up.c build_jobs.c main.c
OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
