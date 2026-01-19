/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:25:35 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/19 10:14:48 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int n)
{
	char	arr[11];
	ssize_t	nb;
	int		i;
	int		j;
	char	*out;

	i = 10;
	nb = (ssize_t)n;
	if (n == 0)
		arr[--i] = '0';
	if (n < 0)
		nb *= -1;
	while (nb)
	{
		arr[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		arr[--i] = '-';
	out = malloc((11 - i) * sizeof(char));
	if (!out)
		return (NULL);
	j = 0;
	while (arr[i])
		out[j++] = arr[i++];
	return (out);
}

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
	int		i;
	int		atoi;
	char	*itoa;

	if (argc <= 1)
		return (printf("\n"));
	i = 1;
	while (i < argc)
	{
		atoi = ft_atoi(argv[i]);
		printf("%d\n", atoi);
		itoa = ft_itoa(atoi);
		printf("%s\n", itoa);
		i++;
	}
	return (0);
}
