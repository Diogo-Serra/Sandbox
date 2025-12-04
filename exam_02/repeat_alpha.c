/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:12:59 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/04 22:22:43 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(void)
{
	char	alpha;
	int		i;
	int		d;

	alpha = 'a';
	i = 1;
	while (alpha <= 'z')
	{
		d = i;
		while (d--)
			write(1, &alpha, 1);
		i++;
		alpha++;
	}
}
