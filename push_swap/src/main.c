/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:03:50 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/16 15:51:24 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **a, t_stack **b, int *move_count)
{
	int	size;

	size = stack_size(*a);
	if (stack_is_sorted(*a))
		return ;
	if (size <= 5)
		sort_small(a, b, move_count);
	else
		radix_sort(a, b, move_count);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		move_count;

	a = NULL;
	b = NULL;
	move_count = 0;
	if (argc < 2)
		return (0);
	a = parse_input(argc, argv);
	if (!a)
		return (1);
	if (stack_has_duplicates(a))
	{
		error_exit(&a, &b);
		return (1);
	}
	push_swap(&a, &b, &move_count);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
