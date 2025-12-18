/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:38:55 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/18 15:55:26 by diosoare         ###   ########.fr       */
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

void	add_front(t_person **head, t_person *new_node)
{
	new_node->next = *head;
	*head = new_node->next;
}

t_person	*create_person(char *name, int age)
{
	t_person	*new_person;
	size_t		i;
	
	new_person = malloc(sizeof(t_person));
	if (!new_person)
		return (NULL);
	new_person->age = age;
	new_person->next = NULL;
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
	
	person1 = create_person("Diogo", 35);
	person2 = create_person("Viktoriia", 26);
	add_front(&head, person1);
	add_front(&head, person2);
	printf("%d, %s\n", person1->age, person1->name);
	printf("%d, %s\n", person2->age, person2->name);
	return (0);
}
