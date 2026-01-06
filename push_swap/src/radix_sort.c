/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:10:29 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/06 11:18:43 by diosoare         ###   ########.fr       */
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

static int	get_index(t_stack *stack, int value)
{
	t_stack	*tmp;
	int		index;

	tmp = stack;
	index = 0;
	while (tmp)
	{
		if (value > tmp->value)
			index++;
		tmp = tmp->next;
	}
	return (index);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	index;

	size = stack_size(*a);
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			index = get_index(*a, (*a)->value);
			if (((index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
