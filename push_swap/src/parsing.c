/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:06:24 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/16 18:34:29 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_and_add(t_stack **a, char *str)
{
	long	num;

	if (!is_valid_number(str))
		error_exit(a, NULL);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		error_exit(a, NULL);
	add_number(a, num);
}

void	process_split(t_stack **a, char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		validate_and_add(a, split[j]);
		j++;
	}
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*a;
	char	**split;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !*split)
		{
			if (split)
				free(split);
			error_exit(&a, NULL);
		}
		process_split(&a, split);
		free_split(split);
		i++;
	}
	return (a);
}
