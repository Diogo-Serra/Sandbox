/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:27:02 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/21 00:20:27 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
	char			*name;
	int				age;
	struct s_list	*next;
}	t_list;

int	ft_atoi(char *source)
{
	int i;
	int	sign;
	int	result;
	
	i = 0;
	sign = 1;
	result = 0;
	while (source[i] == ' ' || (source[i] >= 9 && source[i] <= 13))
		i++;
	if (source[i] == '+' || source[i] == '-')
	{
		if (source[i] == '-')
			sign *= -1;
		i++;
	}
	while (source[i] >= '0' && source[i] <= '9')
		result = result * 10 + (source[i++] - '0');
	return (result * sign);
}

t_list	*new_node(char *name, int age)
{
	t_list	*new_node;
	
	if (!name || !age)
		return (NULL);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->name = name;
	new_node->age = age;
	return (new_node);
}

void	add_front(t_list **head, t_list *node)
{
	node->next = *head;
	*head = node;
}

void	add_back(t_list **head, t_list *node)
{
	t_list	*current;
	
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

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		printf("%s\n%d\n", current->name, current->age);
		current = current->next;
	}
}

void free_lst(t_list *head)
{
	t_list *tmp;
	t_list *current;

	current = head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*person;
	int		i;
	
	head = NULL;
	if (argc <= 1)
		printf("\n");
	i = 1;
	while (i < argc)
	{
		person = new_node(argv[i], ft_atoi(argv[i + 1]));
		i += 2;
		add_back(&head, person);
	}
	print_list(head);
	free_lst(head);
	return (0);
}
