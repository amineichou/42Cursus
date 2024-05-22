NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRC = philo.c parser.c utils.c ft_start_philo.c
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