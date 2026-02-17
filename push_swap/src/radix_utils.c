/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:30:00 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/17 14:27:48 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*create_sorted_array(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_stack	*current;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = stack;
	i = 0;
	while (current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort_array(arr, size);
	return (arr);
}

static int	find_index_in_sorted(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indices(t_stack *stack)
{
	int		*sorted;
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	sorted = create_sorted_array(stack, size);
	if (!sorted)
		return ;
	current = stack;
	while (current)
	{
		current->index = find_index_in_sorted(sorted, size, current->value);
		current = current->next;
	}
	free(sorted);
}

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}
