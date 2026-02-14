/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:56:47 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/14 16:48:50 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first two elements of a stack */
static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

/* Push top of src to top of dst */
static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*top;

	if (!*src)
		return ;
	top = *src;
	*src = (*src)->next;
	top->next = *dst;
	*dst = top;
}

/* Rotate: first element becomes last */
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

/* Reverse rotate: last element becomes first */
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* Public operations - print the instruction */
void	operation_handler(t_stack **a, t_stack **b, char *flag)
{
	if (flag[0] == 's' && flag[1] == 'a')
		swap(*a);
	if (flag[0] == 's' && flag[1] == 'b')
		swap(*b);
	if (flag[0] == 's' && flag[1] == 's')
	{
		swap(*a);
		swap(*b);
	}
	if (flag[0] == 'p' && flag[1] == 'a')
		push(a, b);
	if (flag[0] == 'p' && flag[1] == 'b')
		push(b, a);
	if (flag[0] == 'r' && flag[1] == 'a')
		rotate(a);
	if (flag[0] == 'r' && flag[1] == 'b')
		rotate(b);
	if (flag[0] == 'r' && flag[1] == 'r')
	{
		rotate(a);
		rotate(b);
	}
	if (flag[0] == 'r' && flag[1] == 'r' && flag[2] == 'a')
		reverse_rotate(a);
	if (flag[0] == 'r' && flag[1] == 'r' && flag[2] == 'b')
		reverse_rotate(b);
	if (flag[0] == 'r' && flag[1] == 'r' && flag[2] == 'r')
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	ft_putendl_fd(flag, 1);
}
