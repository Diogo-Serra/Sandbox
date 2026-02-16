/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:30:00 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/16 18:29:17 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

static int	get_position(t_stack *stack, int index)
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

static int	find_max_index(t_stack *stack)
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

static void	push_chunk_to_b(t_stack **a, t_stack **b, int chunk_start,
		int chunk_end, int *move_count)
{
	int	size;
	int	pushed;

	pushed = 0;
	size = stack_size(*a);
	while (pushed < (chunk_end - chunk_start + 1) && size > 0)
	{
		if ((*a)->index >= chunk_start && (*a)->index <= chunk_end)
		{
			exec_operation(a, b, "pb", move_count);
			pushed++;
			if (*b && (*b)->next && (*b)->index < chunk_start + (chunk_end
					- chunk_start) / 2)
				exec_operation(NULL, b, "rb", move_count);
		}
		else
			exec_operation(a, NULL, "ra", move_count);
		size--;
	}
}

static void	push_max_to_a(t_stack **a, t_stack **b, int *move_count)
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

void	chunk_sort(t_stack **a, t_stack **b, int *move_count)
{
	int	size;
	int	chunk_size;
	int	chunks;
	int	i;

	assign_indices(*a);
	size = stack_size(*a);
	if (size <= 100)
		chunks = 5;
	else
		chunks = 11;
	chunk_size = size / chunks;
	i = 0;
	while (i < chunks)
	{
		push_chunk_to_b(a, b, i * chunk_size, (i + 1) * chunk_size - 1,
			move_count);
		i++;
	}
	push_chunk_to_b(a, b, i * chunk_size, size - 1, move_count);
	while (*b)
		push_max_to_a(a, b, move_count);
}
