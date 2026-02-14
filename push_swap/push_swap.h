/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:58:03 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/14 16:51:50 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h" 
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* operations.c */
void	operation_handler(t_stack **a, t_stack **b, char *flag);

/* utils.c */
t_stack	*stack_new(int value);
void	stack_add_front(t_stack **stack, t_stack *new_node);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		stack_has_duplicates(t_stack *stack);
t_stack	*stack_min(t_stack *stack);
t_stack	*stack_max(t_stack *stack);
void	stack_print(t_stack *stack);

/* parsing.c */
t_stack	*parse_input(int argc, char **argv);

/* error_handling.c */
void	error_exit(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	free_split(char **split);

/* sort_small.c */
void	sort_small(t_stack **a, t_stack **b);

/* radix_sort.c */
void	radix_sort(t_stack **a, t_stack **b);
void	assign_indices(t_stack *stack);

#endif
