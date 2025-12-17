/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:51:06 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/17 12:17:04 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t	count_words(char *str)
{
	ssize_t	i;
	ssize_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			words++;
		i++;
	}
	return (words);
}

int	main(void)
{
	size_t	words;

	words = count_words("Hello World");
	printf("%i\n", words);
}
