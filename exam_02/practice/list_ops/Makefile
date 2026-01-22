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

# Program name
NAME = list_program

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Source files
SRCS = main.c \
       list_core.c \
       list_algo.c \
       user_input.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADER = list_op.h

# Colors for output
GREEN = \033[0;32m
RESET = \033[0m

# Default rule
all: $(NAME)

# Compile the program
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully! $(RESET)"

# Compile object files
%.o: %. c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)✓ Compiled $<$(RESET)"

# Clean object files
clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Executable removed$(RESET)"

# Rebuild everything
re: fclean all

# Test with different inputs
test: all
	@echo "\n=== Test 1: Command line ==="
	@./$(NAME) 5 3 8 1 9 5
	@echo "\n=== Test 2: Sorted input ==="
	@./$(NAME) 1 2 3 4 5
	@echo "\n=== Test 3: Duplicates ==="
	@./$(NAME) 5 5 5 3 3 1

. PHONY: all clean fclean re test
