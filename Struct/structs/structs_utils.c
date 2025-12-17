/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:14:29 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/12 17:15:21 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	print_list(t_student *head)
{
	t_student	*current;

	current = head;
	while (current)
	{
		printf("%s -> ", current->name);
		current = current->next;
	}
	printf("NULL\n");
}

void	free_list(t_student **head, t_student **tail)
{
	t_student	*current;
	t_student	*temp;

	current = *head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*head = NULL;
	*tail = NULL;
}

void	add_back(t_student **head, t_student **tail, t_student *new_node)
{
	if (!*head)
	{
		*head = new_node;
		*tail = new_node;
		return ;
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

void	add_front(t_student **head, t_student **tail, t_student *new_node)
{
	new_node->next = *head;
	*head = new_node;
	if (!*tail)
		*tail = new_node;
}
