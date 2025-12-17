/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:34:52 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/17 11:06:55 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*epur_str(char *str)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (NULL);
	out = malloc((i + 1) * sizeof(char));
	if (!out)
		return (NULL);
	j = 0;
	while (str[i] && str[i] != ' ' || str[i] != '\t')
		out[j++] = str[i++];
	out[j] = '\0';
	return (out);	
}

int	main(void)
{
	char	*out;

	out = epur_str("  Hello  ");
	printf("%s\n", out);
	return (0);
}
