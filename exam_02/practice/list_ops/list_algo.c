/* ************************************************************************** */
/*                                                                            */
/*                                                        :::       ::::::::   */
/*   list_algorithms.c                                  :+:      :+:     :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 by diosoare              #+#    #+#             */
/*   Updated: 2026/01/22 by diosoare             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"

/*
** Comparison function for sorting
** Returns 0 if a > b (needs swap), 1 otherwise
*/
int	cmp(int a, int b)
{
	if (b < a)
		return (0);
	return (1);
}

/*
** Equality function for duplicate detection
** Returns 0 if equal, 1 if different
*/
int	equal(int a, int b)
{
	if (a == b)
		return (0);
	return (1);
}

/*
** Sorts the list using bubble sort algorithm
** Takes a comparison function pointer as parameter
** Returns:  pointer to head of sorted list
*/
t_list	*sort_list(t_list *list, int (*cmp)(int, int))
{
	t_list	*head;
	int		tmp;

	head = list;
	while (list->next)
	{
		if (cmp(list->data, list->next->data) == 0)
		{
			tmp = list->next->data;
			list->next->data = list->data;
			list->data = tmp;
			list = head;
		}
		else
			list = list->next;
	}
	return (head);
}

/*
** Removes duplicate consecutive values from the list
** Takes an equality function pointer as parameter
** Returns: pointer to head of cleaned list
*/
t_list	*clean_dups(t_list *list, int (*equal)(int, int))
{
	t_list	*head;
	t_list	*tmp;

	head = list;
	while (list->next)
	{
		if (equal(list->data, list->next->data) == 0)
		{
			tmp = list->next->next;
			free(list->next);
			list->next = tmp;
			if (! tmp)
				break ;
		}
		else
			list = list->next;
	}
	return (head);
}
