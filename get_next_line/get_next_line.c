/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:26:08 by diosoare          #+#    #+#             */
/*   Updated: 2025/11/27 15:07:30 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *out;
	char *source1;
	
	source1 = ft_strdup("Hello");
	out = ft_strjoin(source1, " World!");
	printf("Test1 %s\n", out);
	free(out);
	return (0);
}
/* 
char	*get_next_line(int fd)
{	
} */
