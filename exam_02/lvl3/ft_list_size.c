/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:38:55 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/18 18:51:13 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_person
{
	char			name[50];
	int				age;
	struct s_person	*next;
}	t_person;

size_t	count_list(t_person **head)
{
	t_person	*current;
	size_t		count;

	if (!*head)
		return (0);
	current = *head;
	count = 0;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	add_front(t_person **head, t_person *new_node)
{
	new_node->next = *head;
	*head = new_node;
}

t_person	*create_person(char *name, int age)
{
	t_person	*new_person;
	size_t		i;

	if (!name)
		return (NULL);
	new_person = malloc(sizeof(t_person));
	if (!new_person)
		return (NULL);
	new_person->age = age;
	new_person->next = NULL;
	i = 0;
	while (name[i] && i < 49)
	{
		new_person->name[i] = name[i];
		i++;
	}
	new_person->name[i] = '\0';
	return (new_person);
}
/* int	main(void)
{
	t_person	*head;
	t_person	*person1;
	t_person	*person2;
	size_t		list_size;
	
	head = NULL;
	person1 = create_person("Diogo", 35);
	person2 = create_person("Viktoriia", 26);
	add_front(&head, person1);
	add_front(&head, person2);
	printf("%d, %s\n", person1->age, person1->name);
	printf("%d, %s\n", person2->age, person2->name);
	list_size = count_list(&head);
	printf("%zu\n", list_size);
	return (0);
} */
