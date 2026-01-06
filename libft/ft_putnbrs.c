/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:14:46 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/28 17:15:48 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrs(int c)
{
	char		nbr[21];
	long long	n;
	int			i;

	i = 19;
	n = c;
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
