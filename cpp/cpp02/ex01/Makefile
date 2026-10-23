# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/13 15:57:46 by olshklya          #+#    #+#              #
#    Updated: 2026/10/23 14:49:31 by olshklya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fixed_point

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

# controll codes
RESET		=	$(shell printf '\033[0m')
GREEN		=	$(shell printf '\033[32m')
YELLOW		=	$(shell printf '\033[33m')
BLUE		=	$(shell printf '\033[34m')
RED			=	$(shell printf '\033[31m')
UP			=	$(shell printf '\033[A')
CUT			=	$(shell printf '\033[K')

#source files
SRC_FILES	=	main.cpp Fixed.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)

#compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from /ex01...$(RESET)"; else \
	echo "No objects to remove from /ex01."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from /ex01...$(RESET)"; else \
	echo "No Executable to remove from /ex01."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re