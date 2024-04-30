FLAGS = -Wall -Wextra -Werror
CC = cc
SERVER = server
CLIENT = client
SERVER_SRC = server.c
CLIENT_SRC = client.c
UTILS_SRC = utils.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

all: $(SERVER) $(CLIENT) 

$(SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT)

%.o: %.c minitalk.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f server.o client.o utils.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: clean all

.PHONY: all clean fclean re
