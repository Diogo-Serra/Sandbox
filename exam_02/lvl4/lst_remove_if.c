/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:37:32 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/20 11:20:01 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
	void			*data;
	struct s_list	*next;
}	t_list;

t_list	*addto_list(void *data)
{
	t_list	*new_node;
	
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	add_front(t_list **head, t_list *node)
{
	node->next = *head;
	*head = node;
}

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		printf("%s\n", (char *)current->data);
		current = current->next;
	}
}

int	count_list(t_list *head)
{
	int	count;
}

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*node;
	int		i;
	
	head = NULL;
	if (argc <= 1)
		printf("\n");
	i = 1;
	while (i < argc)
	{
		node = addto_list(argv[i++]);
		add_front(&head, node);
	}
	print_list(head);
	return (0);
}
