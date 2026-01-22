/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com>   +#+  +: +       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 by diosoare              #+#    #+#             */
/*   Updated: 2026/01/22 by diosoare             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_OP_H
# define LIST_OP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;


// Create a new node
t_list	*add_node(int data);

// Add node to the front of the list
void	add_front(t_list **head, t_list *node);

// Print the list
void	print_list(t_list *head);

// Free all nodes in the list
void	free_list(t_list *head);

// Sort list in ascending order
t_list	*sort_list(t_list *list, int (*cmp)(int, int));

// Remove duplicate values
t_list	*clean_dups(t_list *list, int (*equal)(int, int));

// Comparison function for sorting
int		cmp(int a, int b);

// Equality function for duplicates
int		equal(int a, int b);

// Parse command line arguments into list
t_list	*parse_args(int ac, char **av);

// Parse comma-separated values
t_list	*parse_csv(char *input);

// Load numbers from file
t_list	*load_from_file(char *filename);

// Interactive mode menu
void	interactive_mode(void);

// Convert string to integer
int		ft_atoi(char *s);

// Print a simple menu
void	print_menu(void);

// Check if string is a valid number
int		is_valid_number(char *s);

// Check if number is in safe range
int		is_safe_range(char *s);

// Print error message
void	print_error(char *msg);

// Print warning message
void	print_warning(void);

// Print a simple menu
void	print_menu(void);

#endif
