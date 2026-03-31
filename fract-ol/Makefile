# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 16:48:46 by olshklya          #+#    #+#              #
#    Updated: 2026/02/24 18:35:00 by olshklya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= fractol

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
MLX_DIR		= minilibx

# Source files
SRCS		= main.c init.c render.c utils.c math_utils.c events.c colors.c

# Object files
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I$(INC_DIR) -I$(MLX_DIR)

# Libraries
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(MLX) $(NAME)

$(NAME): $(OBJS) $(MLX)
	@printf "$(GREEN)Linking $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)$(NAME) created successfully!$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "$(GREEN)Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	@printf "$(GREEN)Compiling MinilibX...$(RESET)\n"
	@make -C $(MLX_DIR) 2>/dev/null || true
	@printf "$(GREEN)MinilibX compiled!$(RESET)\n"

clean:
	@printf "$(RED)Cleaning object files...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@make -C $(MLX_DIR) clean 2>/dev/null || true

fclean: clean
	@printf "$(RED)Removing $(NAME)...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re