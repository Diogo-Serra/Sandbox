/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:23:02 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/09 14:41:30 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	alpha_mirror(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str < 'N')
			*str += 13;
		if (*str >= 'a' && *str < 'n')
			*str += 13;
		if (*str > 'M' && *str <= 'Z')
			*str += 13 - 25;
		if (*str > 'm' && *str <= 'z')
			*str += 13 - 25;
	}
}

int	main(void)
{
	char	str[] = "Hello";
	alpha_mirror(str);
	printf("%s\n", str);
	return (0);
}