/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:00:14 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/18 14:22:41 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

char	*strjoin_expand(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*out;
	char	*expand;

	expand = "   ";
	out = malloc((strlen(s1) + strlen(s2)) + 1);
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		out[i++] = s1[j++];
	n = 0;
	while (expand[n] && (strlen(s1) > 0))
		out[i++] = expand[n++];
	j = 0;
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	return (out);
}
 
char	*expand_str(char *str)
{
	size_t	i;
	char	*out;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		out = malloc(strlen(&str[i]) + 1);
		if (!out)
			return (NULL);
		out = strjoin_expand(out, str);
		i++;
	}
	return (out);
}

int	main(void)
{
	char	str[] = "Hello World Test";
	char	*out;

	out = expand_str(str);
	printf("%s\n", out);
	free(out);
	return (0);
}