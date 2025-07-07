# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 11:58:01 by avinals           #+#    #+#              #
#    Updated: 2025/04/07 11:58:39 by avinals          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

# Directories
LIBFT_DIR		= ./Libft
OBJ_DIR			= obj/

# Files
LIBFT			= $(LIBFT_DIR)/libft.a

SRCS			= main/push_swap.c \
				stack/stack_init.c \
				stack/stack_utils.c \
				error/error.c \
				parsing/mutable_split.c \
				algorithms/init_a_to_b.c \
				algorithms/init_b_to_a.c \
				algorithms/sort_three.c \
				algorithms/sort_stacks.c \
				algorithms/stack_moves.c \
				operations/swap.c \
				operations/push.c \
				operations/rotate.c \
				operations/rev_rotate.c

OBJS			= $(SRCS:%.c=$(OBJ_DIR)%.o)

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I. -I$(LIBFT_DIR)
RM				= rm -f

# Colors for output
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# Rules
all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re