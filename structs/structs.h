/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:01:05 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/12 15:09:01 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_student
{
	char				name[50];
	int					student_id;
	float				grade;
	struct s_student	*next;
}	t_student;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif /* STRUCTS_H */
