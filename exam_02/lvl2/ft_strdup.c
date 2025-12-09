/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:31:11 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 17:44:22 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*out;
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	dup = malloc((i + 1) * sizeof(char));
	out = dup;
	if (!dup)
		return (NULL);
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (out);
}

int	main(int argc, char **argv)
{
	char	*dup;
	
	if (argc == 2)
	{
		dup = ft_strdup(argv[1]);
		printf("%s\n", dup);
		free(dup);
	}
	else
		printf("\n");
	return (0);
}
