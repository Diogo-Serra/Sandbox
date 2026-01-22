/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:27:04 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/22 16:58:29 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"

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
