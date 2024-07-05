NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
SRC =	init.c \
		lst_tools.c \
		mtx_tools.c \
		parser.c \
		philo.c \
		routine.c \
		utils.c \
		utils_2.c

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