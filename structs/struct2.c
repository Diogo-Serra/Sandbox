/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:49:33 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/08 18:38:42 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_student
{
	char				name[50];
	int					student_id;
	float				grade;
	struct s_student	*next;
}	t_student;

t_student	*create_student(char *name, int id, float grade)
{
	t_student	*new_student;
	int	i;

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
	t_student	*student;
	
	student = create_student("Diogo", 35, 18.5);
	printf("%s\n%d\n%f\n", student->name, student->student_id, student->grade);
	free (student);
	return (0);
}