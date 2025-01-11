NAME = megaphone

CC = c++ -std=c++98
FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): megaphone.cpp
	$(CC) $(FLAGS) -o $(NAME) megaphone.cpp

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: clean