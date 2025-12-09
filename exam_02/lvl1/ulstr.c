/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:26:49 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/08 17:41:20 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ulstr(char	*str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str >= 'A' && *str <= 'Z' && count % 2 != 0)
			*str += 32;
		if (*str >= 'a' && *str <= 'z' && count % 2 == 0)
			*str -= 32;
		count++;
		str++;
	}
}
