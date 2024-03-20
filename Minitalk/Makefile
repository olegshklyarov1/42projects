
SRC = client.c server.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -Llibft -lft


all: server client

server: $(OBJ) libft
	$(CC) -o $@ server.o $(LIBS)

client: $(OBJ) libft
	$(CC) -o $@ client.o $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

libft:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f server client
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft