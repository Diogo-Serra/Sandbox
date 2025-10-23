/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:34:27 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/23 15:30:23 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_strslen(const char *src, char c)
{
	int	*data;
	size_t	len;
	int	spaces;
	int	words;

	if (!src)
		return (NULL);
	len = 0;
	spaces = 0;
	words = 0;
	while (src[len])
	{
		if (src[len] == c)
			spaces++;
		if (src[len] != c && (len == 0 || src[len - 1] == c))
			words++;
		len++;
	}
	data = malloc(3 * sizeof(int));
	if (!data)
		return (NULL);
	data[0] = (int)len; // len
	data[1] = spaces; //spaces
	data[2] = words; // words
	return (data);
}

int	ft_wordlen(const char *src, char c)
{
	int i;

	i = 0;
	while (*src && src[i] != c)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
  while (*s && *s == (char)c)
        s++;
    return ((char *)s);
}

char **ft_split(const char *src, char c)
{
	char	**tab;
	int		*data;
	int		i;
	int		j;

	data = ft_strslen(src, c);
	tab = malloc(data[2] * sizeof(char) + 1);
	if (!tab)
		return (NULL);
	i = 0;
	src = ft_strchr(src, (int)c);
	while (*src)
	{
		j = 0;
		tab[i] = malloc ((ft_wordlen(src, c) + 1) * sizeof(char));
		if (!tab[i])
			return (NULL);
		while (*src && *src != c)
			tab[i][j++] = *src++;
		tab[i][j] = '\0';
		i++;
		src = ft_strchr(src, (int)c);	
	}
	tab[i] = NULL;
	return (tab);
}

int	main(void)
{
	char	src[] = "Escola 42 Success";
	char	**result;
	int		i;

	i = 0;
	result = ft_split(src, ' ');
	while (result[i])
		printf("%s\n", result[i++]);
	free(result);
	return (0);
}
