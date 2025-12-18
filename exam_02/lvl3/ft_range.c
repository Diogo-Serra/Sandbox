/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:12:22 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/18 16:58:31 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_range(int start, int	end)
{
	while (start < end)
		printf("%s\n", start);
	start++;
}

int	main(void)
{
	size_t	total;

	total = ft_range(1, 5);
	printf("%zu\n", total);
	return (0);
}