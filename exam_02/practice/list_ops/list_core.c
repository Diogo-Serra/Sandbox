/* ************************************************************************** */
/*                                                                            */
/*                                                        :::       ::::::::   */
/*   list_core.c                                        :+:      :+:     :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 by diosoare              #+#    #+#             */
/*   Updated: 2026/01/22 by diosoare             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"

/*
** Creates a new node with the given data
** Returns:  pointer to new node, or NULL if malloc fails
*/
t_list	*add_node(int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (! new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

/*
** Adds a node to the front of the list
** This modifies the head pointer
*/
void	add_front(t_list **head, t_list *node)
{
	node->next = *head;
	*head = node;
}

/*
** Prints all elements in the list with arrows between them
*/
void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	if (!current)
	{
		printf("(empty list)\n");
		return ;
	}
	while (current)
	{
		printf("%d", current->data);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf("\n");
}

/*
** Frees all nodes in the list
** Important: Always call this before program ends! 
*/
void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*tmp;

	current = head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

/*
** Simple atoi implementation
** Handles spaces, signs, and digits
*/
int	ft_atoi(char *s)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
