/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:10:29 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/14 16:58:22 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while (max_index >> bits)
		bits++;
	return (bits);
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

void	radix_sort(t_stack **a, t_stack **b, int *move_count)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	assign_indices(*a);
	size = stack_size(*a);
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				operation_handler(a, b, "pb", move_count);
			else
				operation_handler(a, NULL, "ra", move_count);
			j++;
		}
		while (*b)
			operation_handler(a, b, "pa", move_count);
		i++;
	}
}
