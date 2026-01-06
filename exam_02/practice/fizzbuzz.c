/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:57:37 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/06 13:58:12 by diosoare         ###   ########.fr       */
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
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			write(1, "FizzBuzz\n", 9);
			i++;
		}
		else if (i % 3 == 0)
		{
			write(1, "Fizz\n", 5);
			i++;			
		}
		else if (i % 5 == 0)
		{
			write(1, "Buzz\n", 5);
			i++;
		}
		else 
		{
			ft_putnbr(i);
			write(1, "\n", 1);
			i++;	
		}
	}
}

int	main(void)
{
	fizz_buzz();
	return (0);
}
