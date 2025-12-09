/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:40:35 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/04 21:48:22 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int digit)
{
	char	arr[3];
	int		i;

	i = 3;
	while (digit)
	{
		arr[--i] = (digit % 10) + '0';
		digit /= 10;
	}
	write(1, &arr[i], 3 - i);
	write(1, "\n", 1);
}

void	fizzbuzz(void)
{
	int	i;

	i = 0;
	while (i++ < 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
			putnbr(i);
	}
}
