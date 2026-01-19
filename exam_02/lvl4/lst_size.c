/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:35:38 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/19 18:13:29 by diosoare         ###   ########.fr       */
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

void	list_remove_if(t_person **begin_list, void *data_ref, int (*cmp)())
{
	t_person	*current;
	t_person	*prev;

	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	prev = NULL;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = current->next;
			else
				prev->next = current->next;
			free(current);
			if (prev == NULL)
				current = *begin_list;
			else
				current = prev->next;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	print_lst(t_person *head)
{
	t_person	*current;

	current = head;
	while (current)
	{
		if (!current->next)
			printf("%s\n", (char *)current->data);
		else		
			printf("%s -> ", (char *)current->data);
		current = current->next;
	}
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

void	free_lst(t_person *head)
{
	t_person	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
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
	}
	count = lst_size(head);
	printf("%d\n", count);
	print_lst(head);	
	free_lst(head);
	return (0);
}
