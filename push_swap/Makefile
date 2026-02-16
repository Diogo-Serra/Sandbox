# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/06 09:51:54 by diosoare          #+#    #+#              #
#    Updated: 2026/02/16 18:29:17 by diosoare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

LIBFT_DIR	:= ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a

SRCS		:= \
				src/main.c \
				src/parsing.c \
				src/operations.c \
				src/sort_small.c \
				src/chunk_sort.c \
				src/utils.c \
				src/utils2.c \
				src/error_handling.c

OBJS		:= $(SRCS:.c=.o)

# **************************************************************************** #

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
