/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:27:02 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/20 23:26:11 by diosoare         ###   ########.fr       */
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
	i++;
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

int	main(int argc, char **argv)
{
	t_list	*person;
	int		i;
	
	if (argc <= 1)
		printf("\n");
	i = 1;
	while (i < argc)
	{
		person = new_node(argv[i], ft_atoi(argv[i + 1]));
		printf("---\nName: %s\nAge: %d\n---\n", person->name, person->age);
		i += 2;
	}
	return (0);
}
