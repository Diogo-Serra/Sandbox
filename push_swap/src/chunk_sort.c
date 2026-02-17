/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:30:00 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/17 04:08:26 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

static int	get_value_position(t_stack *stack, int value)
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

static void	sort_three(t_stack **a, int *move_count)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		exec_operation(a, NULL, "sa", move_count);
	else if (first > second && second > third)
	{
		exec_operation(a, NULL, "sa", move_count);
		exec_reverse_operation(a, NULL, "rra", move_count);
	}
	else if (first > second && second < third && first > third)
		exec_operation(a, NULL, "ra", move_count);
	else if (first < second && second > third && first < third)
	{
		exec_operation(a, NULL, "sa", move_count);
		exec_operation(a, NULL, "ra", move_count);
	}
	else if (first < second && second > third && first > third)
		exec_reverse_operation(a, NULL, "rra", move_count);
}

static void	push_min_to_b(t_stack **a, t_stack **b, int *move_count)
{
	t_stack	*min_node;
	int		min_pos;
	int		size;

	min_node = stack_min(*a);
	min_pos = get_value_position(*a, min_node->value);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while ((*a)->value != min_node->value)
			exec_operation(a, NULL, "ra", move_count);
	}
	else
	{
		while ((*a)->value != min_node->value)
			exec_reverse_operation(a, NULL, "rra", move_count);
	}
	exec_operation(a, b, "pb", move_count);
}

static void	sort_small(t_stack **a, t_stack **b, int size, int *move_count)
{
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			exec_operation(a, NULL, "sa", move_count);
	}
	else if (size == 3)
		sort_three(a, move_count);
	else if (size == 4)
	{
		push_min_to_b(a, b, move_count);
		sort_three(a, move_count);
		exec_operation(a, b, "pa", move_count);
	}
	else if (size == 5)
	{
		push_min_to_b(a, b, move_count);
		push_min_to_b(a, b, move_count);
		sort_three(a, move_count);
		exec_operation(a, b, "pa", move_count);
		exec_operation(a, b, "pa", move_count);
	}
}

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

static void	push_chunk_to_b(t_stack **a, t_stack **b, t_chunk chunk)
{
	int	size;
	int	pushed;

	pushed = 0;
	size = stack_size(*a);
	while (pushed < (chunk.end - chunk.start + 1) && size > 0)
	{
		if ((*a)->index >= chunk.start && (*a)->index <= chunk.end)
		{
			exec_operation(a, b, "pb", chunk.move_count);
			pushed++;
			if (*b && (*b)->next && (*b)->index < (chunk.start + chunk.end) / 2)
				exec_operation(NULL, b, "rb", chunk.move_count);
		}
		else
			exec_operation(a, NULL, "ra", chunk.move_count);
		size--;
	}
}

static void	init_chunk_params(t_chunk *chunk, int size, int *move_count)
{
	int	chunks;
	int	chunk_size;

	if (size <= 16)
		chunks = 1;
	else if (size <= 100)
		chunks = 5;
	else if (size <= 250)
		chunks = 10;
	else
		chunks = 12;
	chunk_size = size / chunks;
	chunk->move_count = move_count;
	chunk->chunk_size = chunk_size;
	chunk->chunks = chunks;
}

static void	push_all_chunks(t_stack **a, t_stack **b, t_chunk chunk, int size)
{
	int	i;

	i = 0;
	while (i < chunk.chunks)
	{
		chunk.start = i * chunk.chunk_size;
		chunk.end = (i + 1) * chunk.chunk_size - 1;
		push_chunk_to_b(a, b, chunk);
		i++;
	}
	chunk.start = i * chunk.chunk_size;
	chunk.end = size - 1;
	push_chunk_to_b(a, b, chunk);
}

void	chunk_sort(t_stack **a, t_stack **b, int *move_count)
{
	t_chunk	chunk;
	int		size;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_small(a, b, size, move_count);
		return ;
	}
	assign_indices(*a);
	init_chunk_params(&chunk, size, move_count);
	push_all_chunks(a, b, chunk, size);
	while (*b)
		push_max_to_a(a, b, move_count);
}
