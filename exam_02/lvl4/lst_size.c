/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:35:38 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/19 14:10:36 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_person {
	void			*data;
	struct s_person	*next;
}	t_person;

t_person	*add_person(void *data)
{
	char		*name;
	t_person	*new_person;
	
	name = (char *)data;
	new_person = malloc(sizeof(t_person));
	if (!new_person)
		return (NULL);
	new_person->data = name;
	new_person->next = NULL;
	return (new_person);
}

void	add_front(t_person **head, t_person *node)
{
	node->next = *head;
	*head = node;	
}

int	lst_size(t_person *head)
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
	int			i;
	int			count;
	t_person	*head;
	t_person	*person;

	head = NULL;
	if (argc <= 1)
		return (printf("\n"), 0);
	i = 1;
	while (i < argc)
	{
		person = add_person(argv[i++]);
		add_front(&head, person);
		printf("%s\n", (char *)person->data);
		free(person);		
	}
	count = lst_size(head);
	printf("%d\n", count);	
	return (0);
}
