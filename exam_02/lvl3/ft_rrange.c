/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:57:48 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/18 18:58:32 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int		*arr;
	int		count;
	int		i;

	count = end - start + 1;
	arr = malloc(count * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (i < count)
		arr[i++] = start++;
	return (arr);
}
