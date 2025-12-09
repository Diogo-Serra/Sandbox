/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:23:02 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 14:46:47 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	alpha_mirror(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'M')
			*str += 13;
		else if (*str >= 'a' && *str <= 'm')
			*str += 13;
		else if (*str > 'M' && *str <= 'Z')
			*str -= 12;
		else if (*str > 'm' && *str <= 'z')
			*str -= 12;
		str++;
	}
}
