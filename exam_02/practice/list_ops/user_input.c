/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +: +         +:+     */
/*   By: diosoare <diosoare@student.42lisboa. com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 by diosoare              #+#    #+#             */
/*   Updated: 2026/01/22 by diosoare             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"
#include <string.h>

/*
** Parse command line arguments into a linked list
** Returns NULL if any argument is invalid
*/
t_list	*parse_args(int ac, char **av)
{
	t_list	*head;
	t_list	*node;
	int		i;
	int		count;

	head = NULL;
	count = 0;
	i = 1;
	
	// Check for too many arguments
	if (ac > 50)
	{
		print_error("Too many arguments!  Maximum:  50 numbers");
		print_warning();
		return (NULL);
	}
	
	while (i < ac)
	{
		// Validate each argument
		if (!is_valid_number(av[i]))
		{
			printf("Invalid argument: '%s'\n", av[i]);
			print_error("All arguments must be valid integers!");
			free_list(head);
			return (NULL);
		}
		
		if (! is_safe_range(av[i]))
		{
			printf("Number out of range: '%s'\n", av[i]);
			print_error("Number exceeds safe integer range!");
			free_list(head);
			return (NULL);
		}
		
		node = add_node(ft_atoi(av[i]));
		if (!node)
		{
			print_error("Memory allocation failed!");
			free_list(head);
			return (NULL);
		}
		add_front(&head, node);
		count++;
		i++;
	}
	
	// Warn if list is getting large
	if (count > 20)
		print_warning();
	
	return (head);
}

/*
** Parse comma-separated values
** Returns NULL if input is invalid
*/
t_list	*parse_csv(char *input)
{
	t_list	*head;
	t_list	*node;
	char	*token;
	char	*input_copy;
	int		count;

	head = NULL;
	count = 0;
	
	// Check for empty input
	if (!input || input[0] == '\0' || input[0] == '\n')
	{
		print_error("Empty input!  Please enter numbers separated by commas.");
		return (NULL);
	}
	
	input_copy = strdup(input);
	if (!input_copy)
	{
		print_error("Memory allocation failed!");
		return (NULL);
	}
	
	token = strtok(input_copy, ",");
	while (token)
	{
		// Skip whitespace
		while (*token == ' ' || *token == '\t')
			token++;
		
		// Validate token
		if (!is_valid_number(token))
		{
			printf("Invalid number: '%s'\n", token);
			print_error("All values must be valid integers!");
			free(input_copy);
			free_list(head);
			return (NULL);
		}
		
		if (!is_safe_range(token))
		{
			printf("Number out of range: '%s'\n", token);
			print_error("Number exceeds safe integer range!");
			free(input_copy);
			free_list(head);
			return (NULL);
		}
		
		node = add_node(ft_atoi(token));
		if (!node)
		{
			print_error("Memory allocation failed!");
			free(input_copy);
			free_list(head);
			return (NULL);
		}
		add_front(&head, node);
		count++;
		
		// Check for too many numbers
		if (count > 50)
		{
			print_error("Too many numbers! Maximum:  50");
			free(input_copy);
			free_list(head);
			return (NULL);
		}
		
		token = strtok(NULL, ",");
	}
	
	free(input_copy);
	
	if (count == 0)
	{
		print_error("No valid numbers found!");
		return (NULL);
	}
	
	if (count > 20)
		print_warning();
	
	return (head);
}

/*
** Load numbers from a file (one number per line)
** Returns NULL if file cannot be opened or contains invalid data
*/
t_list	*load_from_file(char *filename)
{
	FILE	*file;
	t_list	*head;
	t_list	*node;
	char	buffer[256];
	int		line_num;
	int		count;

	head = NULL;
	line_num = 0;
	count = 0;
	
	// Try to open file
	file = fopen(filename, "r");
	if (!file)
	{
		printf("Cannot open file: '%s'\n", filename);
		print_error("File not found or no permission to read!");
		return (NULL);
	}
	
	// Read line by line
	while (fgets(buffer, sizeof(buffer), file))
	{
		line_num++;
		
		// Skip empty lines
		if (buffer[0] == '\n' || buffer[0] == '\0')
			continue;
		
		// Validate number
		if (!is_valid_number(buffer))
		{
			printf("Line %d: Invalid number '%s'\n", line_num, buffer);
			print_error("File contains invalid data!");
			fclose(file);
			free_list(head);
			return (NULL);
		}
		
		if (!is_safe_range(buffer))
		{
			printf("Line %d: Number out of range\n", line_num);
			print_error("Number exceeds safe integer range!");
			fclose(file);
			free_list(head);
			return (NULL);
		}
		
		node = add_node(ft_atoi(buffer));
		if (!node)
		{
			print_error("Memory allocation failed!");
			fclose(file);
			free_list(head);
			return (NULL);
		}
		add_front(&head, node);
		count++;
		
		// Check for too many numbers
		if (count > 100)
		{
			print_error("File too large! Maximum: 100 numbers");
			fclose(file);
			free_list(head);
			return (NULL);
		}
	}
	
	fclose(file);
	
	if (count == 0)
	{
		print_error("File is empty or contains no valid numbers!");
		return (NULL);
	}
	
	printf("✓ Loaded %d numbers from '%s'\n", count, filename);
	
	if (count > 20)
		print_warning();
	
	return (head);
}

/*
** Print a simple menu
*/
void	print_menu(void)
{
	printf("\n=== LINKED LIST OPERATIONS ===\n");
	printf("1. Add number\n");
	printf("2. View list\n");
	printf("3. Sort list\n");
	printf("4. Remove duplicates\n");
	printf("5. Sort and clean\n");
	printf("6. Exit\n");
	printf("Choice: ");
}

/*
** Interactive mode with menu and error handling
*/
void	interactive_mode(void)
{
	t_list	*head;
	t_list	*node;
	char	buffer[256];
	int		choice;
	int		number;
	int		count;

	head = NULL;
	count = 0;
	
	print_warning();
	
	while (1)
	{
		print_menu();
		
		if (! fgets(buffer, sizeof(buffer), stdin))
			break;
		
		if (! is_valid_number(buffer))
		{
			print_error("Invalid choice! Enter a number 1-6");
			continue;
		}
		
		choice = ft_atoi(buffer);
		
		if (choice == 1)
		{
			if (count >= 50)
			{
				print_error("List is full! Maximum: 50 numbers");
				continue;
			}
			
			printf("Enter number: ");
			if (!fgets(buffer, sizeof(buffer), stdin))
				break;
			
			if (!is_valid_number(buffer))
			{
				print_error("Invalid input! Must be an integer.");
				continue;
			}
			
			if (!is_safe_range(buffer))
			{
				print_error("Number out of safe range!");
				continue;
			}
			
			number = ft_atoi(buffer);
			node = add_node(number);
			if (!node)
			{
				print_error("Memory allocation failed!");
				continue;
			}
			add_front(&head, node);
			count++;
			printf("✓ Added %d to list\n", number);
		}
		else if (choice == 2)
		{
			if (!head)
			{
				printf("List is empty!\n");
				continue;
			}
			printf("Current list: ");
			print_list(head);
		}
		else if (choice == 3)
		{
			if (!head)
			{
				print_error("List is empty!  Add numbers first.");
				continue;
			}
			head = sort_list(head, cmp);
			printf("✓ List sorted!\n");
		}
		else if (choice == 4)
		{
			if (!head)
			{
				print_error("List is empty! Add numbers first.");
				continue;
			}
			head = clean_dups(head, equal);
			printf("✓ Duplicates removed!\n");
		}
		else if (choice == 5)
		{
			if (!head)
			{
				print_error("List is empty! Add numbers first.");
				continue;
			}
			head = sort_list(head, cmp);
			head = clean_dups(head, equal);
			printf("✓ List sorted and cleaned!\n");
			print_list(head);
		}
		else if (choice == 6)
		{
			free_list(head);
			printf("\n✓ Goodbye!\n\n");
			return ;
		}
		else
		{
			print_error("Invalid choice! Choose 1-6");
		}
	}
	
	free_list(head);
}
