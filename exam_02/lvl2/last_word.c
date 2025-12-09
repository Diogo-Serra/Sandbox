/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:16:14 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 22:42:58 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	last_word(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	s--;
	while (s >= start && (*s == ' ' || *s == '\t'))
		s--;
	while (s >= start && (*s != ' ' && *s != '\t'))
		s--;
	s++;
	while (*s && (*s != ' ' && *s != '\t'))
	{
		write(1, s, 1);
		s++;		
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		last_word(argv[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}