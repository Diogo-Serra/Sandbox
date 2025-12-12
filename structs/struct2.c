/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:49:33 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/12 16:28:08 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	free_list(t_student **head, t_student **tail)
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
	*tail = NULL;
}

void	add_back(t_student **head, t_student **tail, t_student *new_node)
{
	if (!*head)
	{
		*head = new_node;
		*tail = new_node;
		return ;
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

void	add_front(t_student **head, t_student **tail, t_student *new_node)
{
	new_node->next = *head;
	*head = new_node;
	if (!*tail)
		*tail = new_node;
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
	t_student	*tail;
	t_student	*s1;
	t_student	*s2;
	t_student	*s3;

	head = NULL;
	tail = NULL;
	s1 = create_student("Test1", 35, 18.50);
	printf("%s\n%d\n%f\n", s1->name, s1->student_id, s1->grade);
	add_front(&head, &tail, s1);
	s2 = create_student("Test2", 30, 19.50);
	printf("%s\n%d\n%f\n", s2->name, s2->student_id, s2->grade);
	add_front(&head, &tail, s2);
	s3 = create_student("Test3", 25, 15.50);
	printf("%s\n%d\n%f\n", s3->name, s3->student_id, s3->grade);
	add_back(&head, &tail, s3);
	free_list(&head, &tail);
	return (0);
}
