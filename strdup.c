/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserra <diserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:44:50 by diserra           #+#    #+#             */
/*   Updated: 2025/09/17 01:12:22 by diserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s)
{
	char 	*out;
	size_t	len;
	size_t	i;

	len = strlen(s);
	out = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!out)
		return (NULL);
	while (i <= len)
	{
		out[i] = s[i];
		i++;
	}
	return (out);
}
