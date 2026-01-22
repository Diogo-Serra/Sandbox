# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 16:27:32 by diosoare          #+#    #+#              #
#    Updated: 2026/01/22 16:56:09 by diosoare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := list_ops

CC       := cc
CFLAGS   := -Wall -Wextra -Werror -I.
RM       := rm -f

SRCS := \
	list_algo.c list_core.c user_input.c main.c \

OBJS := $(SRCS:.c=.o)

%.o: %.c list_op.h
	$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re