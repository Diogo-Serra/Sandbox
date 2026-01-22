# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +: +         +:+      #
#    By: diosoare <diosoare@student.42lisboa. com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 by diosoare              #+#    #+#              #
#    Updated: 2026/01/22 by diosoare             ###   ########. fr        #
#                                                                              #
# **************************************************************************** #

NAME     := list_ops

CC       := cc
CFLAGS   := -Wall -Wextra -Werror -I. 
RM       := rm -f

SRCS := \
	list_algo.c list_core.c user_input.c error_handling.c \
	main.c

OBJS := $(SRCS:.c=.o)

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ $(NAME) compiled successfully!"

%.o: %.c list_op.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

. PHONY: all clean fclean re
