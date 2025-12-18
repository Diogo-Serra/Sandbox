/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:00:14 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/18 13:16:34 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t	word_len(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

size_t	count_words(char *str)
{
	size_t	nwords;
	size_t	i;

	i = 0;
	nwords = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] != ' '))
			nwords++;
		i++;
	}
	return (nwords);
}

char	*expand_str(char *str)
{
	char	**storage;
	size_t	wordlen;
	size_t	nwords;
	size_t	i;

	nwords = count_words(str);
	wordlen = word_len(str);
	printf("%i\n", nwords);
}

int	main(void)
{
	char	str[] = "Hello World!";
	char	*out;

	out = expand_str(str);
	printf("%s\n", out);
	return (0);
}