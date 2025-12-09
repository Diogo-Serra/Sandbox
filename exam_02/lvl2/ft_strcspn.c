/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:15:27 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 17:30:20 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (reject[i])
		{
			if (*s == reject[i])
				return (count);
			i++;
		}
		s++;
		count++;
	}
	return (count);
}
