/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:03:54 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/21 14:09:45 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i) & 1;
		bit = bit + '0';
		write(1, &bit, 1);
	}

}
int	main(void)
{
	print_bits(2);
	write(1, "\n", 1);
	print_bits(255);
	write(1, "\n", 1);
	print_bits(0);
	write(1, "\n", 1);
	return (0);
}
