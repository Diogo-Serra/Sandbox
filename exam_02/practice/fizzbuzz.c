/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:57:37 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/06 13:47:33 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	arr[11];
	ssize_t	digit;
	ssize_t	i;

	i = 11;
	digit = nb;
	if (nb < 0)
		digit = -nb;
	if (digit == 0)
		arr[--i] = '0';
	while (digit)
	{
		arr[--i] = (digit % 10) + '0';
		digit /= 10;
	}
	if (nb < 0)
		arr[--i] = '-';
	write(1, arr + i, 11 - i);
}

void	fizz_buzz(void)
{
	
}

int	main(void)
{
	ft_putnbr(-52);
	return (0);
}
