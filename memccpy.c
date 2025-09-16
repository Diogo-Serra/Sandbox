/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserra <diserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:17:12 by diserra           #+#    #+#             */
/*   Updated: 2025/09/16 22:32:29 by diserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		ch;
	unsigned char		*d;
	size_t				i;
	

	s = (const unsigned char *)src;
	ch = (const unsigned char)c;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n && s[i] != ch)
		d[i] = s[i++];
	return (dest + i + 1);
}
