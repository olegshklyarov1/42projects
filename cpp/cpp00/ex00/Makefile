# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/11 16:53:53 by olshklya          #+#    #+#              #
#    Updated: 2026/08/11 16:54:53 by olshklya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CXX	= g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS	= megaphone.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re