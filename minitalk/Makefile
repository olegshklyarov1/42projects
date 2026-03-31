SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = minitalk.h 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: server client

bonus: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	rm -f $(HEADERS:.h=.h.gch)
	make -C libft clean
	
fclean: clean
	rm -f server client
	make -C libft fclean

re: fclean all

.PHONY: all bonus libft clean fclean re