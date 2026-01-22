/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:27:08 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/22 16:59:22 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"

t_list  *add_node(int data)
{
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

void    add_front(t_list **head, t_list *node)
{
    node->next = *head;
    *head = node;
}

void    print_list(t_list *head)
{
    t_list  *current;

    current = head;
    while (current)
    {
        if (!current->next)
            printf("%d\n", current->data);
        else
            printf("%d -> ", current->data);
        current = current->next;
    }
	printf("\n");
}

void    free_list(t_list *head)
{
    t_list  *current;
    t_list  *tmp;

    current = head;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
}

int ft_atoi(char *s)
{
    int sign;
    int result;

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
