/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:02:59 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/22 16:13:21 by diosoare         ###   ########.fr       */
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

int equal(int a, int b)
{
    if (a == b)
        return (0);
    return (1);
}

int cmp(int a, int b)
{
    if (b < a)
        return (0);
    return (1);
}

t_list  *clean_dups(t_list  *list, int (*equal)(int, int))
{
    t_list  *head;
    t_list  *tmp;
    
    head = list;
    while (list->next)
    {
        if (equal(list->data, list->next->data) == 0)
        {
            tmp = list->next->next;
            free(list->next);
            list->next = tmp;
            list = head;
        }
        else
            list = list->next;
    }
    return (head);
}

t_list  *sort_list(t_list   *list, int (*cmp)(int, int))
{
    t_list  *head;
    int     tmp;

    head = list;
    while (list->next)
    {
        if (cmp(list->data, list->next->data) == 0)
        {
            tmp = list->next->data;
            list->next->data = list->data;
            list->data = tmp;
            list = head;
        }
        else
            list = list->next;
    }
    return (head);
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
    sort_list(head, cmp);
    print_list(head);
    clean_dups(head, equal);
    print_list(head);
    free_list(head);
    return (0);
}

