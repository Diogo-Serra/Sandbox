/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:51:02 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/29 23:45:06 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countWords(const char *src, char c)
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

size_t	ft_lenWords(const char *src, char c)
{
	size_t	i;
	
	i = 0;
	while (src[i] && src[i] != c)
		i++;
	return (i);
}

void	*ft_freeHeap(char **src)
{
	size_t	i;
	
	i = 0;
	while (src[i])
		free(src[i++]);
	free(src);
	return (NULL);
}

char **ft_split(char const *s, char c)
{
	char	**dst;
	size_t	lenWords;
	size_t	nWords;
	size_t	i;
		
	i = 0;
	nWords = ft_countWords(s, c);
	dst = (char **)ft_calloc(nWords + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	while (i < nWords)
	{
		while (*s && *s == c)
			s++;
		lenWords = ft_lenWords(s, c);
		dst[i] = ft_calloc(lenWords + 1, sizeof(char));
		if (!dst[i])
			return (ft_freeHeap(dst));
		ft_memcpy(dst[i], s, lenWords);
		s += lenWords;
		i++;
	}
	return (dst);
}

int	main(void)
{
	char	test[] = "Escola 42 Lisboa";
	char	sep = ' ';

	char	**tab;
	size_t	nWords;
	size_t	i;

	tab = ft_split(test, sep);
	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
	i = 0;
	ft_freeHeap(tab);
	return (0);
}