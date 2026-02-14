/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:09:52 by diosoare          #+#    #+#             */
/*   Updated: 2026/02/14 16:50:38 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	stack_add_front(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

void	stack_clear(t_stack **stack)
{
	free_stack(stack);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)  
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_has_duplicates(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*check;

	curr = stack;
	while (curr)
	{
		check = curr->next;
		while (check)
		{
			if (curr->value == check->value)
				return (1);
			check = check->next;
		}
		curr = curr->next;
	}
	return (0);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*stack_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	stack_print(t_stack *stack)
{
	char	*str;

	ft_putstr_fd("Sorted: ", 1);
	while (stack)
	{
		str = ft_itoa(stack->value);
		ft_putstr_fd(str, 1);
		if (stack->next)
			ft_putstr_fd(" ", 1);
		free(str);
		stack = stack->next;
	}
	ft_putstr_fd("\n", 1);
}
