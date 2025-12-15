/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:17:39 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/15 16:26:28 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int nb)
{
	char	arr[11];
	char	*out;
	int		i;
	int		j;
	ssize_t	nbr;

	nbr = nb;
	i = 10;
	if (nb == 0)
		arr[--i] = '0';
	if (nb < 0)
		nbr = -nb;
	while (nbr)
	{
		arr[--i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (nb < 0)
		arr[--i] = '-';
	out = malloc(11 - i);
	if (!out)
		return (NULL);
	j = 0;
	while (i < 10)
		out[j++] = arr[i++];
	out[j] = '\0';
	return (out);
}
