/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:04:03 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/21 21:10:58 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
	int				data;
	struct s_list 	*next;
}	t_list;

int	ft_atoi(char *s)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

int	cmp(int a, int b)
{
	if (a > b)
		return (0);
	return (1);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		tmp;
	t_list	*current;

	current = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = current;
		}
		else
			lst = lst->next;
	}
	lst = current;
	return (lst);
}

t_list	*add_node(int data)
{
	t_list	*new_node;
	
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = (NULL);
	return (new_node);
}

void	add_front(t_list **head, t_list *node)
{
	node->next = *head;
	*head = node;
}

void	print_lst(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		if (!current->next)
			printf("%d\n", current->data);
		else
			printf("%d -> ", current->data);
		current = current->next;
	}
}

void	free_lst(t_list *head)
{
	t_list	*current;
	t_list	*tmp;
	
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
	int	i;
	t_list	*head;
	t_list	*node;

	head = (NULL);
	if (ac <= 1)
		return (printf("\n"), 0);
	i = 1;
	while (i < ac)
	{
		node = add_node(ft_atoi(av[i++]));
		add_front(&head, node);
	}
	print_lst(head);
	sort_list(head, cmp);
	print_lst(head);
	free_lst(head);	
	return (0);
}
