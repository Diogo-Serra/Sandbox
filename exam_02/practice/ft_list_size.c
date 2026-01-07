/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:10:30 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/07 15:04:55 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_person
{
	char			name[50];
	int				age;
	struct s_person	*next;
}	t_person;

t_person	*add_person(char *name, int age)
{
	t_person	*new_person;
	int			i;

	if (!name || !age)
		return (NULL);
	new_person = malloc(sizeof(t_person));
	if (!new_person)
		return (NULL);
	i = 0;
	while (name[i])
	{
		new_person->name[i] = name[i];
		i++;
	}
	new_person->name[i] = '\0';
	new_person->age = age;
	new_person->next = NULL;
	return (new_person);
}

ssize_t	lst_size(t_person **head)
{
	t_person	*current;
	ssize_t		count;

	current = *head;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;		
	}
	return (count);
}

void	add_front(t_person **head, t_person *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

int	main(void)
{
	t_person	*head;
	t_person	*person1;
	t_person	*person2;
	ssize_t		sizelst;

	head = NULL;
	person1 = add_person("Diogo", 35);
	person2 = add_person("Di", 30);
	add_front(&head, person1);	
	add_front(&head, person2);
	printf("%s , %d\n", person1->name, person1->age);
	printf("%s , %d\n", person2->name, person2->age);
	sizelst = lst_size(&head);
	printf("%zu\n", sizelst);	
	return (0);
}
