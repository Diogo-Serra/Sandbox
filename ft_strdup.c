/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:41:10 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/29 11:56:31 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	len;

	if (!s) // original not protected
		return (NULL);
	len = ft_strlen(s);
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, s, len);
	return (out);
}
