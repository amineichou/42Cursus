NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror  -g -fsanitize=thread
SRC = ./ft_init_simulation.c \
			./mtx_tools.c \
			./parser.c \
			./philo.c \
			./routines.c \
			./test.c \
			./utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all