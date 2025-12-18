/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:51:02 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/18 13:21:59 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *src, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (src[i])
	{
		if (src[i] != c && (i == 0 || src[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

size_t	word_len(const char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	return (i);
}

void	*free_heap(char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
		free(src[i++]);
	free(src);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	words_len;
	size_t	n_words;
	size_t	i;

	i = 0;
	n_words = count_words(s, c);
	dst = (char **)ft_calloc(n_words + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	while (i < n_words)
	{
		while (*s && *s == c)
			s++;
		words_len = word_len(s, c);
		dst[i] = ft_calloc(words_len + 1, sizeof(char));
		if (!dst[i])
			return (free_heap(dst));
		ft_memcpy(dst[i], s, words_len);
		s += words_len;
		i++;
	}
	return (dst);
}
/* 
int	main(void)
{
	char	test[] = "Escola 42 Lisboa";
	char	sep = ' ';

	char	**tab;
	size_t	i;

	tab = ft_split(test, sep);
	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
	i = 0;
	free_heap(tab);
	return (0);
} */