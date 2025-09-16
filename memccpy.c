/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserra <diserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:12:25 by diserra           #+#    #+#             */
/*   Updated: 2025/09/14 21:52:33 by diserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char		*s;
	unsigned char 			*d;
	size_t					i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
