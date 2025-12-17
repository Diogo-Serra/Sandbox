/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:51:06 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/17 12:47:23 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t	word_len(char *str)
{
	ssize_t	len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

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

char	*expand_str(char *str)
{
	ssize_t	words;
	ssize_t	total_len;
	ssize_t	len;

	total_len = 0;
	words = count_words(str);
	while (words > 0)
	{
		len = word_len(str);
		total_len += len;
		str += len;
		while (*str == ' ')
			str++;
		words--;
	}
	printf("%zu\n", total_len);
	return (NULL);
}

int	main(void)
{
	size_t	words;
	char	test[] = "Hello World!";

	words = count_words(test);
	expand_str(test);
	printf("%zu\n", words);
}
