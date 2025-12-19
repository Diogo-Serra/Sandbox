/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:09:33 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/19 14:50:26 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	word_len(char *src, char sep)
{
	size_t	len;

	len = 0;
	while (src[len] && src[len] != sep)
		len++;
	return (len);
}

size_t	count_words(char *src, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[i])
	{
		if (src[i] != sep && (i == 0 || src[i - 1] == sep))
			count++;
		i++;
	}
	return (count);
}

void	free_heap(char **src, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
		free(src[i++]);
	free(src);
}

char	*ft_strdup(char *src, char sep)
{
	char	*dup;
	size_t	wordlen;

	wordlen = word_len(src, sep);
	dup = malloc(wordlen * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	wordlen = 0;
	while (src[wordlen] && src[wordlen] != sep)
	{
		dup[wordlen] = src[wordlen];
		wordlen++;
	}	
	dup[wordlen] = '\0';
	return (dup);
}

char	**ft_split(char	*src, char	sep)
{
	char	**split;
	size_t	wordslen;
	size_t	nwords;
	size_t	i;
	size_t	j;

	if (!src || !sep)
		return (NULL);
	nwords = count_words(src, sep);
	split = (char **)malloc(nwords * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (nwords)
	{
		while (src[j] == sep)
			j++;
		wordslen = word_len(&src[j], sep);
		split[i] = ft_strdup(&src[j], sep);
		if (!split[i])
			return (free_heap(split, i), NULL);
		j += wordslen;
		nwords--;
		i++;
	}
	return (split);
}

int	main(void)
{
	char	src[] = "Hello World Test!";
	char	sep = ' ';
	char	**split;
	size_t	i;
	size_t	nwords;
	
	split = ft_split(src, sep);	
	nwords = count_words(&src[0], sep);
	i = 0;
	while (nwords--)
		printf("%s\n", split[i++]);
	free_heap(split, i);
	return (0);
}
