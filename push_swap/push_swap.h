/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:58:03 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/06 11:01:53 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"          // From your libft (ft_atoi, ft_split, ft_lstnew, etc.)
# include <stdlib.h>
# include <unistd.h>

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

/* parsing.c */

/* error_handling.c */

/* sort_small.c */

/* sort_big.c */

/* radix_sort.c */

/* main.c */
void	push_swap(t_stack **a, t_stack **b);

#endif
