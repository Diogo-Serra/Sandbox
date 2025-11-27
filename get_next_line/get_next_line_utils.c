/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:26:34 by diosoare          #+#    #+#             */
/*   Updated: 2025/11/27 15:00:57 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *source)
{
	size_t	i;

	i = 0;
	while (source[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *storage, int newline)
{
	char		ch;

	ch = (unsigned char)newline;
	while (*storage)
	{
		if (*storage == ch)
			return ((char *)storage);
		storage++;
	}
	if (ch == '\0')
		return ((char *)storage);
	return (NULL);
}

char	*ft_strdup(const char *source)
{
	char	*dup;
	size_t	i;

	i = 0;
	i = ft_strlen(source);
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = -1;
	while (source[++i])
		dup[i] = source[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *storage, char const *buffer)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (!storage || !buffer)
		return (NULL);
	out = (char *)malloc((ft_strlen(storage) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = -1;
	while (storage[++i])
		out[i] = storage[i];
	j = -1;
	while (buffer[++j])
		out[i + j] = buffer[j];
	out[i + j] = '\0';
	free(storage);
	return (out);
}
