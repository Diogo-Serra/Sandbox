/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:41:10 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/24 16:22:27 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
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
