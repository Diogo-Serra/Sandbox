/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:34:52 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/17 10:48:19 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*epur_str(char *str)
{
	size_t	i;
	char	*out;

	out = NULL;
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] || str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] || str[i] != ' ' || str[i] != '\t')
		i++;
	out = malloc((i + 1) * sizeof(char));
	if (!out)
		return (NULL);
	out[i-- + 1] = '\0';
	i = 0;
	while (*str || *str == ' ' || *str == '\t')
		str++;
	while (*str || *str != ' ' || *str != '\t')
		out[i++] = *str++;
	return (out);
}

int	main(void)
{
	char	*out;

	out = epur_str("   Hello World   ");
	printf("%s\n", out);
	return (0);
}
