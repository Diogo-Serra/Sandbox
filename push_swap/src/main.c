/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:03:50 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/06 11:03:57 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main sorting dispatcher
** If stack is already sorted → do nothing
** If size <= 5 → use optimized small sort
** Else → use radix sort (best for large random inputs)
*/
static void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (stack_is_sorted(*a))
		return ;
	if (size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
}

/*
** Entry point
** - No arguments → exit silently (as required)
** - Parse input → build stack a
** - On error → print "Error\n" and exit
** - Sort and output operations
** - Free everything
*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);                          // No args → nothing to do
	a = parse_input(argc, argv);
	if (!a)                                   // Parsing failed (error already printed)
		return (1);
	if (stack_has_duplicates(a))              // Duplicates detected in parsing
	{
		error_exit(&a, &b);
		return (1);
	}
	push_swap(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
