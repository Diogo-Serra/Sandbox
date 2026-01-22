/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:02:59 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/22 15:27:38 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int             data;
    struct s_list   *next;
}   t_list;

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

int main(int ac, char **av)
{
    int     i;
    t_list  *node;
    t_list  *head;
    
    head = NULL;
    if (ac <= 1)
        printf("\n");
    i = 1;
    while (i < ac)
    {
        node = add_node(ft_atoi(av[i++]));
        add_front(&head, node);
    }
    print_list(head);
    return (0);
}

