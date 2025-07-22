# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 11:58:01 by avinals           #+#    #+#              #
#    Updated: 2025/07/22 11:58:39 by avinals          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIBFT_DIR		= ./Libft
OBJ_DIR			= obj
MLX_DIR			= ./minilibx-linux

CC				= cc
CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I. -I$(LIBFT_DIR) -I$(MLX_DIR)
RM				= rm -f

LIBFT			= $(LIBFT_DIR)/libft.a
MLX_LIB			= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lbsd -lm -lXext -lX11


SRCS	= main.c \
		map_checks.c \
		map_init.c \
		map_utils.c \
		game.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Colors
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# Rules
all:	$(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make bonus -s -C $(LIBFT_DIR)

$(MLX_LIB):
	@echo "$(GREEN)Building MLX...$(RESET)"
	@make -s -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@make clean -s -C $(LIBFT_DIR)
	@-make clean -s -C $(MLX_DIR) 2>/dev/null || true

fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@$(RM) $(NAME)
	@make fclean -s -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus