/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:12:39 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/17 09:52:23 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	print_list(t_person **head)
{
	t_person	*current;

	if (!*head)
		return ;
	current = *head;
	while (current)
	{
		printf("Person: %s, %i\n", current->name, current->age);
		current = current->next;
	}
}

void	add_back(t_person **head, t_person *new_node)
{
	t_person	*current;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

void	add_front(t_person **head, t_person *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

t_person	*add_person(int age, char *name)
{
	t_person	*new_person;
	int			i;

	if (!age || !*name)
		return (NULL);
	new_person = malloc(sizeof(t_person));
	new_person->next = NULL;
	new_person->age = age;
	i = 0;
	while (name[i])
	{
		new_person->name[i] = name[i];
		i++;
	}
	new_person->name[i] = '\0';
	return (new_person);
}

int	main(void)
{
	t_person	*head;
	t_person	*person1;
	t_person	*person2;
	t_person	*person3;
	
	head = NULL;
	person1 = add_person(35, "Diogo");
	person2 = add_person(30, "Sara");
	person3 = add_person(25, "Tiago");
	add_front(&head, person1);
	add_front(&head, person2);
	add_back(&head, person3);
	print_list(&head);
	free(person1);
	free(person2);
	free(person3);
	return (0);
}
