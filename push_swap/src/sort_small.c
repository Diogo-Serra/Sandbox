/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:15:24 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/14 16:48:16 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		operation_handler(a, NULL, "sa");
	else if (first > second && second > third)
	{
		operation_handler(a, NULL, "sa");
		operation_handler(a, NULL, "rra");
	}
	else if (first > second && second < third && first > third)
		operation_handler(a, NULL, "ra");
	else if (first < second && second > third && first < third)
	{
		operation_handler(a, NULL, "sa");
		operation_handler(a, NULL, "ra");
	}
	else if (first < second && second > third && first > third)
		operation_handler(a, NULL, "rra");
}

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	int		min_pos;
	int		size;

	min_node = stack_min(*a);
	min_pos = get_position(*a, min_node->value);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while ((*a)->value != min_node->value)
			operation_handler(a, NULL, "ra");
	}
	else
	{
		while ((*a)->value != min_node->value)
			operation_handler(a, NULL, "rra");
	}
	operation_handler(a, b, "pb");
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			operation_handler(a, NULL, "sa");
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
	{
		push_min_to_b(a, b);
		sort_three(a);
		operation_handler(a, b, "pa");
	}
	else if (size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		sort_three(a);
		operation_handler(a, b, "pa");
		operation_handler(a, b, "pa");
	}
}
