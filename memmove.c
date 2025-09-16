/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserra <diserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 01:07:39 by diserra           #+#    #+#             */
/*   Updated: 2025/09/14 21:52:32 by diserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*memmove(void *dest, const void *src, size_t n)
{
	const unsigned char *s;
	unsigned char 		*d;
	unsigned char		*out;
	size_t				i;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	out = malloc((char *)(strlen(src)));
}
