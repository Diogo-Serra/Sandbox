/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:58:03 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/06 11:08:44 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"          // From your libft (ft_atoi, ft_split, ft_lstnew, etc.)
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;      // The integer value from input
	struct s_stack	*next;      // Next element (towards bottom of stack)
}					t_stack;

/* operations.c */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* utils.c */
t_stack	*stack_new(int value);
void	stack_add_front(t_stack **stack, t_stack *new_node);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		stack_has_duplicates(t_stack *stack);
t_stack	*stack_min(t_stack *stack);
t_stack	*stack_max(t_stack *stack);
int		get_position(t_stack *stack, int value);

/* parsing.c */
t_stack	*parse_input(int argc, char **argv);

/* error_handling.c */
void	error_exit(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	free_split(char **split);

/* sort_small.c */
void	sort_small(t_stack **a, t_stack **b);

/* sort_big.c */
void	sort_big(t_stack **a, t_stack **b);

/* radix_sort.c */
void	radix_sort(t_stack **a, t_stack **b);

/* main.c */
void	push_swap(t_stack **a, t_stack **b);

#endif
