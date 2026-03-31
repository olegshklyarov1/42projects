# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olshklya <olshklya@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/30 19:36:59 by olshklya          #+#    #+#              #
#    Updated: 2026/03/30 20:01:04 by olshklya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread
SRCS = main.c init.c philo.c monitor.c utils.c
OBJS = $(SRCS:.c=.o)

all = $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean = rm -f $(OBJS)

fclean = rm -f $(NAME)

re = fclean all

.PHONY: all clean fclean re
