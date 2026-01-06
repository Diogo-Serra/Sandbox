/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:37:05 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/25 01:30:53 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	total = nmemb * size;
	if (nmemb == 0 || size == 0)
		total = 1;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

char	*ft_itoa(int n)
{
	char	nbr[20];
	char	*out;
	long	nb;
	int		i;

	nb = (long)n;
	i = sizeof(nbr);
	if (nb == 0)
		nbr[--i] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb)
	{
		nbr[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		nbr[--i] = '-';
	out = (char *)ft_calloc(sizeof(nbr) - i, sizeof(char));
	if (!out)
		return (NULL);
	out = ft_memcpy(out, nbr + i, sizeof(nbr) - i);
	return (out);
}
