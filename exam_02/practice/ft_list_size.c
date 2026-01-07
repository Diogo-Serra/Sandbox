/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:10:30 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/07 14:49:34 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_person
{
	char			*name;
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
	new_person->age = age;
	new_person->next = NULL;
	return (new_person);
}

int		lst_size(t_person **head)
{
	
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
	
	return (0);
}