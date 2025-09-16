/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserra <diserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:33:35 by diserra           #+#    #+#             */
/*   Updated: 2025/09/16 22:10:52 by diserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	digit;
	char	c;

	digit = nb;
	if (digit < 0)
	{
		write(1, "-", 1);
		digit = -digit;
	}
	if (digit >= 10)
		ft_putnbr(digit / 10);
	c = (digit % 10) + '0';
	write(1, &c, 1);
}

int	ft_atoi(const char *s)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return ((int)(result * sign));
}

int	main(int argc, char **argv)
{
	int	size;
	int	result;

	size = 1;
	result = 0;
	if (argc == 1)
		write(1, "Error\n", 6);
	while (size < argc)
	{
		write(1, "Results:\n", 9);
		result = ft_atoi(argv[size]);
		ft_putnbr(result);
		write(1, "\n", 1);
		size++;
	}
	return (0);
}
