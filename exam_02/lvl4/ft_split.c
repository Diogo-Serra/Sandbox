/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:09:33 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/19 13:25:21 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	count_words(char *src, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[i])
	{
		if (src[i] != sep && (i == 0 || src[i - 1] == sep))
			count++;
		i++;
	}
	return (count);
}

/* char	**ft_split(char	*src, char	sep)
{
	
}
 */
int	main(void)
{
	char	src[] = "Hello World Test!";
	char	sep = ' ';

	printf("%zu\n", count_words(src, sep));
	return (0);
}
