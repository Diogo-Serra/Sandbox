/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:15:01 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/04 21:21:53 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*out = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (out);
}

int	main()
{
	char	dest[6];
	
	ft_strcpy(dest, "Hello");
	printf("Teste: %s\n", dest);	
	return (0);
}