/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:37:07 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 18:45:20 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	count;
	int		found;

	count = 0;
	while (*s)
	{
		i = 0;
		found = 0;
		while (accept[i])
		{
			if (*s == accept[i])
			{
				found = 1;
				break ;
			}
			i++;
		}
		if (!found)
			return (count);
		count++;
		s++;
	}
	return (count);
}
