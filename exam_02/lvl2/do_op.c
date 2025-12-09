/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:29 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 16:19:46 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	atoi(char *str)
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
	while (*str)
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	main(void)
{
	int a;

	a = atoi("42");
	printf("%d\n", a);
	return (0);
/* 	int		a;
	int		b;
	char	op;
	int		result;
	
	if (argc == 4)
	{
		a = atoi(argv[1]);
		op = (argv[2][0]);
		b = atoi(argv[3]);
		
		if (op == '+')
			result = a + b;
		if (op == '-')
			result = a - b;				
		if (op == '/')
			result = a / b;				
		if (op == '*')
			result = a * b;
		printf("%d\n");
	}
	else
		printf("\n");
	return (0);
 */
}