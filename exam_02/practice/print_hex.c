/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:45:38 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/16 15:54:32 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_atoi_base(char *source, int base)
{
    int i;
    int digit;
    int s;
    int result;

    i = 0;
    digit = 0;
    result = 0;
    while (source[i] == ' ' || (source[i] >= 9 && source[i] <= 13))
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
	    digit = -1;
        if (source[i] >= '0' && source[i] <= '9')
            digit = source[i] - '0';
        if (source[i] >= 'a' && source[i] <= 'f')
            digit = source[i] - 'a' + 10;
        if (source[i] >= 'A' && source[i] <= 'F')
            digit = source[i] - 'A' + 10;
        if (digit == -1 || digit >= base)
            break ;
        result = result * base + digit;
        i++;
	}
    return (result * s);
}

void print_bin(int n)
{
    char *bin_digits = "01";

    if (n >= 2)
        print_bin(n / 2);
    write(1, &bin_digits[n % 2], 1);
}

void print_hex(int n)
{
    char *hex_digits = "0123456789abcdef";
    
    if (n >= 16)
        print_hex(n / 16);
    write(1, &hex_digits[n % 16], 1);
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
        digit = ft_atoi_base(argv[i], 10);
        write(1, "0x", 2);
        print_hex(digit);
        write(1, "\n", 1);
        print_bin(digit);
        write(1, "\n", 1);
       i++;
    }
    return (0);
}
