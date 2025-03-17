# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 11:47:25 by avinals           #+#    #+#              #
#    Updated: 2025/03/17 14:02:41 by avinals-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
// LIBFT_DIR = path/to/libft
// LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
    ar rcs $(NAME) $(OBJS) $



clean:
    $(RM) $(OBJS)
    $(MAKE) -C clean

fclean: clean
    $(RM) $(NAME)
    $(MAKE) -C fclean

re: fclean all

.PHONY: all clean fclean re