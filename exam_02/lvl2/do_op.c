/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:29 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 16:50:23 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int		sign;
	int		result;

	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str)
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	op;
	int		result;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		op = (argv[2][0]);
		b = ft_atoi(argv[3]);
		if (op == '+')
			result = a + b;
		else if (op == '-')
			result = a - b;				
		else if (op == '/')
			result = a / b;				
		else if (op == '*')
			result = a * b;
		printf("%d\n", result);
	}
	else
		printf("\n");
	return (0);
}
