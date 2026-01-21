/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:35:48 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/21 12:39:12 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_person {
	char			*name;
	struct s_person *next;
}	t_person;

t_person	*add_person(char *name)
{
	t_person	*new_person;
	
	if (!name)
		return (NULL);
	new_person = malloc(sizeof(t_person));
	if (new_person)
		return (NULL);
	
}

int	main(int argc, char **argv)
{

	return (0);
}