/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:24:33 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/04 22:27:35 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha2(char	*str)
{
	int	repeat;

	if (*str >= 'a' && *str <= 'z')
		repeat = *str - 'a' + 1;
	else if (*str >= 'A' && *str <= 'Z')
		repeat = *str - 'A' + 1;
	else
		repeat = 1;
	while (repeat--)
		write(1, str, 1);
	str++;
}
