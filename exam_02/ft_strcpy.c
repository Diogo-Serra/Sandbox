/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:15:01 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/04 21:48:45 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*out;

	out = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (out);
}
