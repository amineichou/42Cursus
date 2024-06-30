NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror   #-g -fsanitize=thread # -
SRC = philo.c parser.c utils.c ft_init_simulation.c routines.c
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