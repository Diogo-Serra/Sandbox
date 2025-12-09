/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:12:33 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 23:12:59 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	result;

	i = 8;
	result = 0;
	while (i--)
	{
		result = (result << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (result);
}
