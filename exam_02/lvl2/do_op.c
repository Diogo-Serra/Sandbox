/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:29 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 16:01:38 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

ssize_t	do_op(int a, int b, char op)
{
	if (op == '+')
		return ((ssize_t)a + b);
	if (op == '-')
		return ((ssize_t)a - b);	
	if (op == '/')
		return ((ssize_t)a / b);	
	if (op == '*')
		return ((ssize_t)a * b);
	return (0);		
}

int	main(int argc, char	**argv)
{
	int		a;
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
	printf("%d\n");
	
}