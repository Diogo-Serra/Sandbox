/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:56:47 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/14 18:26:37 by diosoare         ###   ########.fr       */
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

/* Execute normal operations: sa, sb, ss, pa, pb, ra, rb, rr */
void	exec_operation(t_stack **a, t_stack **b, char *flag, int *move_count)
{
	if (flag[0] == 's' && flag[1] == 'a')
		swap(*a);
	else if (flag[0] == 's' && flag[1] == 'b')
		swap(*b);
	else if (flag[0] == 's')
	{
		swap(*a);
		swap(*b);
	}
	else if (flag[0] == 'p' && flag[1] == 'a')
		push(a, b);
	else if (flag[0] == 'p')
		push(b, a);
	else if (flag[1] == 'a')
		rotate(a);
	else if (flag[1] == 'b')
		rotate(b);
	else
	{
		rotate(a);
		rotate(b);
	}
	ft_putendl_fd(flag, 1);
	if (move_count)
		(*move_count)++;
}

/* Execute reverse operations: rra, rrb, rrr */
void	exec_reverse_operation(t_stack **a, t_stack **b, char *flag,
			int *move_count)
{
	if (flag[2] == 'a')
		reverse_rotate(a);
	else if (flag[2] == 'b')
		reverse_rotate(b);
	else
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	ft_putendl_fd(flag, 1);
	if (move_count)
		(*move_count)++;
}
