/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:45:38 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/16 15:09:19 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *source)
{
    int i;
    int d;
    int s;

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
    while (source[i] >= '0' && source[i] <= '9')
        d = d * 10 + (source[i++] - '0');
    return (d * s);
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
