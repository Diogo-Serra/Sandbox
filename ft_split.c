/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:34:27 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/23 14:41:10 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_strslen(char *src)
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
		if (src[len] == ' ')
			spaces++;
		if (src[len] != ' ' && (len == 0 || src[len - 1] == ' '))
			words++;
		len++;
	}
	data = malloc(3 * sizeof(int));
	if (!data)
		return (NULL);
	data[0] = len; // len
	data[1] = spaces; //spaces
	data[2] = words; // words
	return (data);
}

int	ft_wordlen(char *src)
{
	int i;

	i = 0;
	while (src[i] != ' ')
		i++;
	return (i);
}

char *ft_strchr(char *src, char c)
{
	char *p;

	p = src;
	while (*p)
	{
		if (*p == c)
			src++;
		if (*p != c)
			return (p);
	}
	if (c == '\0')
		return (NULL);
}

char **ft_split(char *src, char c)
{
	char	**tab;
	int		*data;
	int		i;
	int		j;

	data = ft_strslen(src);
	tab = malloc(data[2] * sizeof(char) + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (*src && data[2] > 0)
	{
		j = 0;
		tab[i] = malloc (ft_wordlen(src) * sizeof(char) + 1);
		if (!tab[i])
			return (NULL);
		while (*src != c)
		{
			tab[i][j] = *src++;
			j++;
		}
		tab[i][j + 1] = '\0';
		data[2] -= 1;
		i++;
		src = ft_strchr(src, c);
	}
	return(tab);
}

int	main(void)
{
	char	**result;
	char	src[] = "Success 12 Lisboa 42 Success";
	int		i;
	char	c = ' ';

	i = 0;
	result = ft_split(src, ' ');
	while (result[i])
		printf("%s\n", result[i++]);
	return (0);
}
