FLAGS = -Wall -Wextra -Werror -O3
CC = cc
MLX_LIB = -lmlx -framework OpenGL -framework AppKit
NAME = fractol
FRACTOL_SRC = fractol.c
FRACTOL_OBJ = $(FRACTOL_SRC:.c=.o)
SRC = libft.c utils.c tools.c math.c render_fractol.c start_fractol.c events.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(FRACTOL_OBJ)
	$(CC) $(FLAGS) $(FRACTOL_OBJ) $(OBJ) $(MLX_LIB) -o $(NAME)
	@clear
	@echo "\033[0;31mmusage : ./fractol mandelbrot or ./fractol julia <reel> <i>\033[0;31m"

%.o: %.c fractol.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(FRACTOL_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re