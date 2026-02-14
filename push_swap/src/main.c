/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:03:50 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/14 16:58:22 by diosoare         ###   ########.fr       */
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
	stack_print(a);
	printf("\nTotal moves: %d\n", move_count);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
