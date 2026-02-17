/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:00 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/17 14:36:14 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, int *move_count)
{
	if ((*a)->value > (*a)->next->value)
		exec_operation(a, NULL, "sa", move_count);
}

static int	find_min_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static int	find_max_value(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

static int	find_min_position(t_stack *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	min = find_min_value(stack);
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->value == min)
			min_pos = pos;
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

void	sort_three(t_stack **a, int *move_count)
{
	int	max;

	max = find_max_value(*a);
	if ((*a)->value == max)
	{
		exec_operation(a, NULL, "ra", move_count);
		if ((*a)->value > (*a)->next->value)
			exec_operation(a, NULL, "sa", move_count);
	}
	else if ((*a)->next->value == max)
	{
		exec_reverse_operation(a, NULL, "rra", move_count);
		if ((*a)->value > (*a)->next->value)
			exec_operation(a, NULL, "sa", move_count);
	}
	else if ((*a)->value > (*a)->next->value)
		exec_operation(a, NULL, "sa", move_count);
}

static void	push_min_to_b(t_stack **a, t_stack **b, int *move_count)
{
	int	min_pos;
	int	size;

	size = stack_size(*a);
	min_pos = find_min_position(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			exec_operation(a, NULL, "ra", move_count);
	}
	else
	{
		while (min_pos++ < size)
			exec_reverse_operation(a, NULL, "rra", move_count);
	}
	exec_operation(a, b, "pb", move_count);
}

void	sort_four(t_stack **a, t_stack **b, int *move_count)
{
	push_min_to_b(a, b, move_count);
	sort_three(a, move_count);
	exec_operation(a, b, "pa", move_count);
}

void	sort_five(t_stack **a, t_stack **b, int *move_count)
{
	push_min_to_b(a, b, move_count);
	push_min_to_b(a, b, move_count);
	sort_three(a, move_count);
	exec_operation(a, b, "pa", move_count);
	exec_operation(a, b, "pa", move_count);
}
