/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:30:00 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/16 18:44:41 by diosoare         ###   ########.fr       */
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

	assign_indices(*a);
	size = stack_size(*a);
	init_chunk_params(&chunk, size, move_count);
	push_all_chunks(a, b, chunk, size);
	while (*b)
		push_max_to_a(a, b, move_count);
}
