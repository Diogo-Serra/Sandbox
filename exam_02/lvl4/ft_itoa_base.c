/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:25:35 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/19 09:58:01 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *source)
{
	int		i;
	int		sign;
	int		result;
	
	i = 0;
	sign = 1;
	result = 0;
	while (source[i] == ' ' || source[i] == '\t')
		i++;
	if (source[i] == '+' || source[i] == '-')
	{
		if (source[i] == '-')
			sign *= -1;
		i++;
	}
	while (source[i] >= '0' && source[i] <= '9')
		result = result * 10 + (source[i++] - '0');
	i++;
	return (result * sign);
}
int	main(int argc, char **argv)
{
	int	i;
	int	digit;

	if (argc <= 1)
		return (printf("\n"));
	i = 1;
	while (i < argc)
	{
		digit = ft_atoi(argv[i++]);
		printf("%d\n", digit);
	}
	return (0);
}
