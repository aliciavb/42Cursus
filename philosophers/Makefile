# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 14:36:20 by avinals           #+#    #+#              #
#    Updated: 2025/08/10 14:37:32 by avinals          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo

OBJ_DIR			= obj/

SRCS			= philo.c

OBJS			= $(SRCS:%.c=$(OBJ_DIR)%.o)

CC				= cc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f

# Colors for output
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# Rules
all:	$(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"


$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re