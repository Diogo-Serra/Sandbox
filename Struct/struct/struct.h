/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:06:15 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/17 11:44:50 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_person
{
	int				age;
	char			name[50];
	struct s_person	*next;
}	t_person;

void		add_front(t_person **head, t_person *new_node);
void		add_back(t_person **head, t_person *new_node);
void		print_list(t_person **head);
t_person	*add_person(int age, char *name);

#endif