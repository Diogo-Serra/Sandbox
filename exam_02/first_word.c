/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:04:42 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/04 20:38:38 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(char	*src)
{
	while (*src == ' ')
		src++;
	while (*src && *src != ' ')
		write(1 , src++, 1);
	write(1 , "\n", 1);
}

/* int	main(void)
{
	char *str = NULL;
	first_word(str);
	return (0);
} */