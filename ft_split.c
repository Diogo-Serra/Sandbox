/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:51:02 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/29 21:27:25 by diosoare         ###   ########.fr       */
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
		i++;;
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

void	ft_freeHeap(char **src)
{
	size_t	i;
	
	i = 0;
	while (src)
	{
		free(src[i]);
		i++;
	}
	free(src);
	return (NULL);
}
/*
char **ft_split(char const *s, char c)
{
	
}*/

int	main(void)
{
	size_t res;
	char	*dst;
	
	ft_m
	res = ft_lenWords("asd asd asd asd", ' ');
	printf("%zu", res);
	res = ft_lenWords("asd asd asd asd", ' ');
	printf("%zu", res);
	
	return (0);
}