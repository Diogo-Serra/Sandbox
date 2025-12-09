/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:49:08 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 15:24:10 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*camel_to_snake(char *str)
{
	char	*snake;
	int		d;
	int		i;

	i = 0;
	while (str[i])
		i++;
	snake = malloc((i + 2) * sizeof(char));
	if (!snake)
		return (NULL);
	i = 0;
	d = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			snake[d++] = '_';
			snake[d++] = str[i] + 32;
		}
		else
			snake[d++] = str[i];
		i++;
	}
	snake[d] = '\0';
	return (snake);
}

int	main(void)
{
	char	str[] = "helloWorld";
	char	*snake;
		
	snake = camel_to_snake(str);
	printf("%s\n", snake);
	free (snake);
	return (0);
}