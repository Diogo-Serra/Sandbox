/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:30:49 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/05 22:45:52 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

void	create_coordinates(void)
{
	t_point	coordinate_1;
	t_point coordinate_2;

	coordinate_1.x = 0;
	coordinate_1.y = 0;

	coordinate_2.x = 3;
	coordinate_2.y = 4;

	printf("1x: %d\n1y: %d\n2x: %d\n2y: %d\n", coordinate_1.x, coordinate_1.y, coordinate_2.x, coordinate_2.y);
}

int	main(void)
{
	t_point	first_coordinate;

	first_coordinate.x = 5;
	first_coordinate.y = 10;
	printf("x: %d\ny: %d\n", first_coordinate.x, first_coordinate.y);
	create_coordinates();
	return (0);
}
