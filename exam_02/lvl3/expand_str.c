/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:00:14 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/18 18:49:54 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	wordlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

size_t	strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
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
	out = malloc((strlen(s1) + 3 + wordlen(s2)) + 1);
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		out[i++] = s1[j++];
	n = 0;
	if (j > 0 && s2[0] != '\0')
		while (expand[n])
			out[i++] = expand[n++];
	j = 0;
	while (s2[j] && s2[j] != ' ')
		out[i++] = s2[j++];
	out[i] = '\0';
	free(s1);
	return (out);
}

char	*expand_str(char *str)
{
	size_t	i;
	char	*expanded;

	i = 0;
	expanded = malloc(1);
	if (!expanded)
		return (NULL);
	expanded[0] = '\0';
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		expanded = strjoin_expand(expanded, &str[i]);
		if (!expanded)
			return (NULL);
		i += wordlen(&str[i]);
	}
	return (expanded);
}

/* int	main(void)
{
	char	str[] = "Hello World Test";
	char	*out;

	out = expand_str(str);
	printf("%s\n", out);
	free(out);
	return (0);
} */