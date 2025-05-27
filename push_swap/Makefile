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

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap.c stack_utils.c parser.c error.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re