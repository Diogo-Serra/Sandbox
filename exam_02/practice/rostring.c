/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 02:31:34 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/17 02:32:05 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		start;
	int		end;

	if (argc > 1)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		start = i;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			i++;
		end = i;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		if (argv[1][i])
		{
			while (argv[1][i])
			{
				if ((argv[1][i] == ' ' || argv[1][i] == '\t') && 
					(argv[1][i + 1] && argv[1][i + 1] != ' ' && argv[1][i + 1] != '\t'))
					ft_putchar(' ');
				else if (argv[1][i] != ' ' && argv[1][i] != '\t')
					ft_putchar(argv[1][i]);
				i++;
			}
			ft_putchar(' ');
		}
		while (start < end)
			ft_putchar(argv[1][start++]);
	}
	write(1, "\n", 1);
	return (0);
}
