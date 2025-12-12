/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:49:33 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/12 16:13:28 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	free_list(t_student **head)
{
	t_student	*current;
	t_student	*temp;
	
	current = *head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*head = NULL;
}

void	add_front(t_student **head, t_student *new_node)
{
	new_node->next = *head;
	*head = new_node;
}

t_student	*create_student(char *name, int id, float grade)
{
	t_student	*new_student;
	int			i;

	new_student = malloc(sizeof(t_student));
	if (!new_student)
		return (NULL);
	i = 0;
	while (name[i])
	{
		new_student->name[i] = name[i];
		i++;
	}
	new_student->name[i] = '\0';
	new_student->student_id = id;
	new_student->grade = grade;
	new_student->next = NULL;
	return (new_student);
}

int	main(void)
{
	t_student	*head;
	t_student	*s1;
	t_student	*s2;

	head = NULL;
	s1 = create_student("Diogo", 35, 18.5);
	printf("%s\n%d\n%f\n", s1->name, s1->student_id, s1->grade);
	add_front(&head, s1);
	s2 = create_student("Maria", 30, 19.5);
	add_front(&head, s2);
	printf("%s\n%d\n%f\n", s2->name, s2->student_id, s2->grade);
	free_list(&head);
	return (0);
}
