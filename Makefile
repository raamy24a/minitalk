NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = serveru/server_main.c 
SRC_CLIENT = clientu/client_main.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJS = $(OBJ_SERVER) $(OBJ_CLIENT)

LIBFT = libft/libft.a
PRINTF = printf/printf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: server client

server: serveru/server_main.o libft/libft.a printf/printf.a
	$(CC) $(CFLAGS) serveru/server_main.o libft/libft.a printf/printf.a -o server

client: clientu/client_main.o libft/libft.a printf/printf.a
	$(CC) $(CFLAGS) clientu/client_main.o libft/libft.a printf/printf.a -o client

libft/libft.a:
	$(MAKE) -C libft

printf/printf.a:
	$(MAKE) -C printf

clean:
	rm -f serveru/server_main.o clientu/client_main.o
	$(MAKE) -C libft clean
	$(MAKE) -C printf clean

fclean: clean
	rm -f server client
	$(MAKE) -C libft fclean
	$(MAKE) -C printf fclean

re: fclean all

.PHONY: all clean fclean re
