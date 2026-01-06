/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:10:29 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/06 11:10:32 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = stack_max(stack)->value;
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

static void	index_stack(t_stack **a)
{
	t_stack	*curr;
	t_stack	*tmp;
	int		index;

	curr = *a;
	while (curr)
	{
		tmp = *a;
		index = 0;
		while (tmp)
		{
			if (curr->value > tmp->value)
				index++;
			tmp = tmp->next;
		}
		curr->value = index;
		curr = curr->next;
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	index_stack(a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->value >> i) & 1) == 0)
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
