/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:27:21 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/22 16:49:47 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"

/*
** Usage instructions
*/
static void	print_usage(void)
{
	printf("\n=== LINKED LIST PROGRAM ===\n\n");
	printf("Usage:\n");
	printf("  1. Command line:   ./program 5 3 8 1 9\n");
	printf("  2. From file:     ./program -f numbers.txt\n");
	printf("  3. Interactive:   ./program -i\n");
	printf("  4. Help:          ./program -h\n\n");
}

/*
** Main entry point - handles different input modes
*/

int	main(int ac, char **av)
{
	t_list	*head;

	head = NULL;
	
	// No arguments - show usage
	if (ac == 1)
	{
		print_usage();
		return (0);
	}
	
	// Help flag
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
	{
		print_usage();
		return (0);
	}
	
	// Interactive mode
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'i')
	{
		interactive_mode();
		return (0);
	}
	
	// File input mode
	if (ac == 3 && av[1][0] == '-' && av[1][1] == 'f')
	{
		head = load_from_file(av[2]);
		if (!head)
			return (1);
	}
	// Command line arguments mode
	else
	{
		head = parse_args(ac, av);
	}
	
	// Process the list
	printf("\nOriginal list: ");
	print_list(head);
	
	head = sort_list(head, cmp);
	printf("After sort:     ");
	print_list(head);
	
	head = clean_dups(head, equal);
	printf("After clean:    ");
	print_list(head);
	
	// Clean up
	free_list(head);
	return (0);
}
