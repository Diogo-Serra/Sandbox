/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:27:01 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/22 16:51:01 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"
#include <string.h>

/*
** Parse command line arguments into a linked list
** Example: ./program 5 3 8 1 9
*/
t_list	*parse_args(int ac, char **av)
{
	t_list	*head;
	t_list	*node;
	int		i;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		node = add_node(ft_atoi(av[i]));
		if (node)
			add_front(&head, node);
		i++;
	}
	return (head);
}

/*
** Parse comma-separated values
** Example: "5, 3, 8, 1, 9"
*/
t_list	*parse_csv(char *input)
{
	t_list	*head;
	t_list	*node;
	char	*token;
	char	*input_copy;

	head = NULL;
	input_copy = strdup(input);
	if (!input_copy)
		return (NULL);
	token = strtok(input_copy, ",");
	while (token)
	{
		while (*token == ' ' || *token == '\t')
			token++;
		node = add_node(ft_atoi(token));
		if (node)
			add_front(&head, node);
		token = strtok(NULL, ",");
	}
	free(input_copy);
	return (head);
}

/*
** Load numbers from a file (one number per line)
** Example file content:
**   5
**   3
**   8
*/
t_list	*load_from_file(char *filename)
{
	FILE	*file;
	t_list	*head;
	t_list	*node;
	char	buffer[256];

	head = NULL;
	file = fopen(filename, "r");
	if (!file)
	{
		printf("Error:  Cannot open file '%s'\n", filename);
		return (NULL);
	}
	while (fgets(buffer, sizeof(buffer), file))
	{
		node = add_node(ft_atoi(buffer));
		if (node)
			add_front(&head, node);
	}
	fclose(file);
	printf("Loaded numbers from '%s'\n", filename);
	return (head);
}

/*
** Simple menu
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
** Interactive mode
*/
void	interactive_mode(void)
{
	t_list	*head;
	char	buffer[256];
	int		choice;
	int		number;

	head = NULL;
	while (1)
	{
		print_menu();
		if (! fgets(buffer, sizeof(buffer), stdin))
			break ;
		choice = ft_atoi(buffer);
		if (choice == 1)
		{
			printf("Enter number:  ");
			if (fgets(buffer, sizeof(buffer), stdin))
			{
				number = ft_atoi(buffer);
				add_front(&head, add_node(number));
				printf("Added %d\n", number);
			}
		}
		else if (choice == 2)
		{
			printf("Current list:  ");
			print_list(head);
		}
		else if (choice == 3)
		{
			head = sort_list(head, cmp);
			printf("List sorted!\n");
		}
		else if (choice == 4)
		{
			head = clean_dups(head, equal);
			printf("Duplicates removed!\n");
		}
		else if (choice == 5)
		{
			head = sort_list(head, cmp);
			head = clean_dups(head, equal);
			printf("List sorted and cleaned!\n");
			print_list(head);
		}
		else if (choice == 6)
		{
			free_list(head);
			printf("Goodbye!\n");
			return ;
		}
		else
			printf("Invalid choice!\n");
	}
	free_list(head);
}
