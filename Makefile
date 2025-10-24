# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 14:48:13 by diosoare          #+#    #+#              #
#    Updated: 2025/10/24 14:49:48 by diosoare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := libft.a

CC       := cc
CFLAGS   := -Wall -Wextra -Werror
AR       := ar
ARFLAGS  := rcs
RM       := rm -f

SRCS := \
	ft_atoi.c ft_bzero.c ft_memcpy.c ft_memchr.c ft_memcmp \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putnbr.c ft_strcpy.c \
	ft_strdup.c ft_strlen.c

OBJS := $(SRCS:.c=.o)

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re