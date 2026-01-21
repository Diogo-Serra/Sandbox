/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:35:48 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/21 14:00:33 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_person {
	char			*name;
	struct s_person *next;
}	t_person;

t_person	*add_person(char *name)
{
	t_person	*new_person;

	if (!name)
		return (NULL);
	new_person = malloc(sizeof(t_person));
	if (!new_person)
		return (NULL);
	new_person->name = name;
	new_person->next = NULL;
	return (new_person);
}

void	add_back(t_person **head, t_person *node)
{
	t_person *current;

	current = NULL;
	if (!*head)
	{
		*head = node;
		return ;		
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = node;
}

void	add_front(t_person **head, t_person *node)
{
	node->next = *head;
	*head = node;
}

int	count_list(t_person *head)
{
	t_person	*current;
	int			count;

	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	print_list(t_person *head)
{
	t_person	*current;

	current = head;
	while (current)
	{
		if (!current->next)
			printf("%s\n", current->name);
		else
			printf("%s -> ", current->name);			
		current = current->next;
	}
}

void	free_lst(t_person *head)
{
	t_person *tmp;
	t_person *current;

	current = head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

int	main(int ac, char **av)
{
	int			i;
	t_person	*person;
	t_person	*head;

	// printf("here");
	head = NULL;
	i = 1;
	while (i < ac)
	{
		person = add_person(av[i++]);
		add_back(&head, person);
	}
	printf("%d\n", count_list(head));
	print_list(head);
	free_lst(head);
	return (0);
}
