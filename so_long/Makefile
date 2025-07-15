# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 11:58:01 by avinals           #+#    #+#              #
#    Updated: 2025/07/15 11:58:39 by avinals          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIBFT_DIR		= ./Libft
OBJ_DIR			= obj/

LIBFT			= $(LIBFT_DIR)/libft.a

SRC		= so_long.c

OBJ		= $(OBJ_DIR)so_long.o

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I. -I$(LIBFT_DIR)
RM				= rm -f

# Colors
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# Rules
all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -s -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@make clean -s -C $(LIBFT_DIR)

fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@$(RM) $(NAME)
	@make fclean -s -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus