/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:37:32 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/20 10:48:07 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
	void			*data;
	struct s_list	*next;
}	t_list;

t_list	*addto_list(void *data)
{
	t_list	*new_node;
	char	*name;
	int		i;

	name = (char *)data;
	new_node->data = name;
	new_node->next = NULL;
	return (new_node);
}

int	main(int argc, char **argv)
{

	return (0);
}