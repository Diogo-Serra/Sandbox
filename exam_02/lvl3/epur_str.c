/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:34:52 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/17 11:34:25 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*epur_str(char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*out;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len])
		len++;
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (str[i + 1] && str[i + 1] != ' ' && str[i + 1] != '\t')
				out[j++] = ' ';
		}
		else
			out[j++] = str[i];
		i++;
	}
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
