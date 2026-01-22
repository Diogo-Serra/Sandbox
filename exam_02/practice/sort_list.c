/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:08:26 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/22 01:20:43 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
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
    if (*s == '+' || *s == '-')
    {
        if (*s == '-')
            sign *= -1;
        s++;
    }
    while (*s >= '0' && *s <= '9')
        result = result * 10 + (*s++ - '0');
    return (result * sign);
}

int cmp(int a, int b)
{
    if (a > b)
        return (0);
    return (1);
}

t_list  *sort_list(t_list *head, int (*cmp)(int, int))
{
    t_list  *thead;
    int     tmp;
    
    thead = head;
    while (head->next)
    {
        if (cmp(head->data, head->next->data) == 0)
        {
            tmp = head->next->data;
            head->next->data = head->data;
            head->data = tmp;
        }
        else
            head = head->next;
    }
    head = thead;
    return (head);
}

int main(int ac, char **av)
{
    int     i;
    t_list  *head;
    t_list  *node;

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
    free_list(head);
    return (0);
}
 
