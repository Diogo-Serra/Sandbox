/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:45:38 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/16 15:16:49 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(char *source, int base)
{
    int i;
    int d;
    int s;
    int result;

    i = 0;
    d = 0;
    while (source[i] == ' ' || (source[i] > 9 && source[i] < 13))
        i++;
    s = 1;
    if (source[i] == '+' || source[i] == '-')
    {
        if (source[i] == '-')
            s *= -1;
        i++;
    }
    while (source[i])
    {
	    d = -1;
        if (source[i] >= '0' && source[i] <= '9')
            digit = source[i] - '0';
        if (source[i] >= 'a' && source[i] <= 'f')
            digit = source[i] - 'a' + 'f';
        if (source[i] >= 'A' && source[i] <= 'F')
            digit = source[i] - 'A' + 'F';
        if (digit == -1 || digit >= base)
            break ;
        result = result * base + digit;
        i++;
	}
    return (result * s);
}

int main(int argc, char **argv)
{
    int i;
    int digit;

    if (argc <= 1)
        return (printf("No Args"), 0);
    i = 1;
    while (i < argc)
    {
        digit = ft_atoi(argv[i]);
        printf("%i\n", digit);
        i++;
    }
    return (0);
}
