/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:19:05 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/20 12:21:09 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	count;
	
	i = 1;
	count = 0;
	while (i < argc)
	{
		printf("%s\n", argv[i++]);
		count++;
	}
	printf("Arg Count: %d\n", count);
	return (0);
}
