# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 11:51:44 by oshklyar          #+#    #+#              #
#    Updated: 2023/11/13 16:18:23 by oshklyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c\
ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c\
ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c\
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_atoi.c\
ft_strnstr.c ft_memcmp.c ft_strdup.c ft_calloc.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
ft_putendl_fd.c ft_striteri.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re
