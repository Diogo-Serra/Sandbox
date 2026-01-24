/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:32:20 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/24 14:21:38 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

# define bits "01"

int ft_atoi(char *s)
{
    int sign;
    int result;

    sign = 1;
    result = 0;
    while (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign *= -1;
        s++;
    }
    while (*s >= '0' && *s <= '9')
        result = result * 10 + (*s++ - '0');
    return (result * sign);
}

int main(int ac, char **av)
{
    unsigned char   oct;
    unsigned char   bit;
    int             i;

    if (ac != 2)
        return (write(1, "\n", 1), 0);
    i = 8;
    oct = (unsigned char)(ft_atoi(av[1]));
    while (i--)
    {   
        bit = (oct >> i) + '0';
        write(1, &bits[bit % 2], 1);
    }
    write(1, "\n", 1);
    return (0);
}
