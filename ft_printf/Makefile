NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = ft_puthex.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_unputnbr.c ft_printf.c 
OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re