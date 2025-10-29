/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:27:16 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/29 17:42:55 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

size_t	ft_countwords(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	*free_heap(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	nwords;
	size_t	lenword;

	i = 0;
	nwords = ft_countwords(s, c);
	tab = (char **)ft_calloc(nwords + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (*s && i < nwords)
	{
		while (*s && *s == c)
			s++;
		lenword = ft_wordlen(s, c);
		tab[i] = ft_calloc(lenword + 1, sizeof(char));
		if (!tab[i])
			free_heap(tab);
		ft_memcpy(tab[i++], s, lenword);
		s += lenword;
	}
	return (tab);
}

int	main(void)
{
	char	src[] = "Teste Escola 42 Teste Escola 42";
	char	sep = ' ';

	char	**tab;
	size_t	i;
	size_t	nwords;

	i = 0;
	nwords = ft_countwords(src, sep);
	tab = ft_split(src, sep);
	while (i < nwords)
		printf("%s\n", tab[i++]);
	free_heap(tab);
	return (0);
}
