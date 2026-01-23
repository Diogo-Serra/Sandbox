/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:18:25 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/23 14:52:33 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

# define bits "01"

void    print_bit(unsigned char octect)
{
    int             i;
    unsigned char   bit;

    i = 8;
    while (i--)
    {
        bit = (octect >> i) + '0';
        write(1, &bits[bit % 2], 1); 
    }
}

int main(void)
{
    print_bit(255);
    return (0);
}

