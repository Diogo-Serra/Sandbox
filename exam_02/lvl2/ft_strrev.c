/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:51:53 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 18:25:28 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	while (s[i])
		i++;
	i--;
	j = 0;
	while (j < i)
	{
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		j++;
		i--;
	}
	return (s);
}

int	main(int argc, char **argv)
{
	char	*rev;

	if (argc == 2)
	{
		rev = ft_strrev(argv[1]);
		printf("%s\n", rev);
	}
	else
		printf("\n");
	return (0);
}
