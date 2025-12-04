/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:04:42 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/04 20:32:08 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(char	*src)
{

	while (*src == ' ')
		src++;
	while (*src && *src != ' ')
	{
		write(1 , src, 1);
		src++;
	}		
	write(1 , "\n", 1);
}

int	main(void)
{
	first_word("Escola 42 Teste");
	return (0);
}