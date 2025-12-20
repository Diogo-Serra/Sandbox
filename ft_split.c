/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:31:10 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/20 00:23:48 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *source, char sep)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (source[i] && source[i] != sep)
		i++;
	dup = malloc(i * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (source[i] && source[i] != sep)
	{
		dup[i] = source[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_heap(char **source, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(source[i++]);
	free(source);
}

size_t	strlenw(char *source, char sep)
{
	size_t	i;

	i = 0;
	while (source[i] && source[i] != sep)
		i++;
	return (i);
}

size_t	count_words(char *source, char sep)
{
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 0;
	while (source[i])
	{
		if (source[i] != sep && (i == 0 || source[i - 1] == sep))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *source, char sep)
{
	char	**split;
	size_t	nwords;
	size_t	i;
	size_t	j;

	if (!source)
		return (NULL);
	nwords = count_words(source, sep);
	if (!nwords)
	{
		split = malloc(1 * sizeof(char *));
		if (!split)
			return (NULL);
		split[0] = NULL;
		return (split);
	}
	split = (char **)malloc((nwords + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nwords)
	{
		while (source[j] == sep)
			j++;
		split[i] = ft_strdup(&source[j], sep);
		if (!split[i])
			return (free_heap(split, i), NULL);
		j += strlenw(&source[j], sep);
		i++;
	}
	split[i] = NULL;
	return (split);
}

int	main(void)
{
	char	source[] = "Hello World Test!";
	char	sep = ' ';
	char	**split;
	size_t	nwords;
	size_t	i;

	nwords = count_words(source, sep);
	printf("Words: %zu\n\n", nwords);
	split = ft_split(source, sep);
	if (!split)
		return (0);
	i = 0;
	while (i < nwords)
		printf("%s\n", split[i++]);
	free_heap(split, i);
	return (0);
}
