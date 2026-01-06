/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:06:24 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/06 11:07:01 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	add_number(t_stack **a, long num)
{
	t_stack	*new;

	if (num > INT_MAX || num < INT_MIN)
		error_exit(a, NULL);
	new = stack_new((int)num);
	if (!new)
		error_exit(a, NULL);
	stack_add_front(a, new);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*a;
	char	**split;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !*split)
			error_exit(&a, NULL);
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
				(free_split(split), error_exit(&a, NULL));
			add_number(&a, ft_atol(split[j]));
			j++;
		}
		free_split(split);
		i++;
	}
	return (a);
}
