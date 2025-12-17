/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:12:39 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/17 09:25:05 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_person	*add_person(int age, char *name)
{
	t_person	*new_person;
	int			i;

	if (!age || !*name)
		return ;
	new_person = malloc(sizeof(t_person)); 
	new_person->next = NULL;
	new_person->age = age;
	i = 0;
	while (name[i])
		new_person->name[i] = name[i];
	return (new_person);		
}

int	main(void)
{
	t_person	*person1;

	person1 = add_person(35, "Diogo");
	printf("%d, %s", person1->age, person1->name);
	return (0);
}