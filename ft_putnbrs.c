/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:14:46 by diosoare          #+#    #+#             */
/*   Updated: 2025/10/24 22:47:10 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrs(int	c)
{
	char	nbr[20];
	int		i;

	i = 0;
	ft_memset(nbr, 'n', 19);
	if (c < 0)
	{
		nbr[i++] = '-';
		c *= -1;
	}
	i = 19;
	while (c)
	{
		nbr[i--] = (c % 10) + '0';
		c /= 10;
	}
	i = 0;
	while (nbr[i] && (ft_isdigit(nbr[i]) || nbr[i] == '-'))
		write(1, &nbr[i++], 1);
}

int	main(void)
{
	ft_putnbrs(42);
	write(1, "\n", 1);
	return (0);
}
