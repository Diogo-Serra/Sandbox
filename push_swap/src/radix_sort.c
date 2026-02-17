/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:30:00 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/17 16:18:09 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort_bit(t_stack **a, t_stack **b, int bit, int *move_count)
{
	int	size;
	int	i;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			exec_operation(a, b, "pb", move_count);
		else
			exec_operation(a, NULL, "ra", move_count);
		i++;
	}
	while (*b)
		exec_operation(a, b, "pa", move_count);
}

void	radix_sort(t_stack **a, t_stack **b, int *move_count)
{
	int	max_bits;
	int	bit;

	assign_index(*a);
	max_bits = get_max_bits(stack_size(*a));
	bit = 0;
	while (bit < max_bits)
	{
		radix_sort_bit(a, b, bit, move_count);
		bit++;
	}
}
