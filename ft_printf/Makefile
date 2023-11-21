# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:58:26 by oshklyar          #+#    #+#              #
#    Updated: 2023/11/20 13:57:14 by oshklyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c \
	print_string.c	\
	print_int.c \
	print_char.c \
	print_pointer.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):$(OBJ)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@
	
	
clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
	make re -C libft

.PHONY: all clean fclean re
