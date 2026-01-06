/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:30:49 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/12 17:13:26 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	create_coordinates(void)
{
	t_point	coordinate_1;

	coordinate_1.x = 42;
	coordinate_1.y = 42;
	printf("Created:\nx: %d\ny: %d\n", coordinate_1.x, coordinate_1.y);
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
