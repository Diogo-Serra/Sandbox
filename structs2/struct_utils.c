/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:44:13 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/15 14:53:23 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_player	*create_player(int id, int score, char *name)
{
	t_player	*player;
	int			i;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->id = id;
	player->score = score;
	i = 0;
	while (name[i])
	{
		player->name[i] = name[i];
		i++;
	}
	player->name[i] = '\0';
	player->next = NULL;
	return (player);
}

void	add_front(t_player **head, t_player *new_node)
{
	new_node->next = *head;
	head = &new_node;
}

void	add_back(t_player	**head, t_player *new_node)
{
	t_player	*current;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

void	print_list(t_player **head)
{
	t_player	*current;

	if (!*head)
		return ;
	current = *head;
	while (current)
	{
		printf("%s\n", current->name);
		current = current->next;
	}
	printf("NULL\n");
}
