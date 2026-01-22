/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:20:44 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/22 17:20:55 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"
#include <limits.h>

/*
** Print error message in red (if terminal supports it)
*/
void	print_error(char *msg)
{
	printf("\n❌ ERROR: %s\n\n", msg);
}

/*
** Print warning about program limitations
*/
void	print_warning(void)
{
	printf("\n⚠️  WARNING:\n");
	printf("   This program is designed for SMALL lists.\n");
	printf("   - Recommended:  5-20 numbers\n");
	printf("   - Safe range: -2147483648 to 2147483647\n");
	printf("   - Large lists may cause performance issues\n\n");
}

/*
** Check if string is a valid integer
** Returns:  1 if valid, 0 if invalid
*/
int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	
	// Skip whitespace
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	
	// Check for sign
	if (s[i] == '-' || s[i] == '+')
		i++;
	
	// Must have at least one digit
	if (s[i] < '0' || s[i] > '9')
		return (0);
	
	// Check all remaining chars are digits
	while (s[i])
	{
		if (s[i] == '\n')
			break;
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	
	return (1);
}

/*
** Check if number string is in safe range for int
** Returns: 1 if safe, 0 if too large
*/
int	is_safe_range(char *s)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	
	// Skip whitespace
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	
	// Handle sign
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	
	// Convert to long to check overflow
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		if (num > INT_MAX)
			return (0);
		i++;
	}
	
	num *= sign;
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	
	return (1);
}
