/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:35:48 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/21 13:12:20 by diosoare         ###   ########.fr       */
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
	if (new_person)
		return (NULL);
	new_person->name = name;
	new_person->next = NULL;
}

void	add_front(t_person **head, t_person *node)
{
	node->next = head;
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

int	main(int argc, char **argv)
{

	return (0);
}