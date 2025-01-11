NAME = main

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
COMPILER = c++ -std=c++98
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Fixed.hpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean