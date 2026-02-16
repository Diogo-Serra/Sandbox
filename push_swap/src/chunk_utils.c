/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:30:00 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/16 18:33:11 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	find_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	push_max_to_a(t_stack **a, t_stack **b, int *move_count)
{
	int	max_idx;
	int	pos;
	int	size;

	max_idx = find_max_index(*b);
	pos = get_position(*b, max_idx);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while ((*b)->index != max_idx)
			exec_operation(NULL, b, "rb", move_count);
	}
	else
	{
		while ((*b)->index != max_idx)
			exec_reverse_operation(NULL, b, "rrb", move_count);
	}
	exec_operation(a, b, "pa", move_count);
}
