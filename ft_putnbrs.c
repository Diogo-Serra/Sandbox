/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:14:46 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/25 00:51:39 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

void	ft_putnbrs(int c)
{
	char	nbr[20];
	long	n;
	int		i;

	i = 19;
	n = (long)c;
	ft_memset(nbr, 0, sizeof(nbr));
	if (c == 0)
		nbr[--i] = '0';
	if (c < 0)
		n = -n;
	while (n)
	{
		nbr[--i] = (n % 10) + '0';
		n /= 10;
	}
	if (c < 0)
		nbr[--i] = '-';
	write(1, nbr + i, 19 - i);
}
