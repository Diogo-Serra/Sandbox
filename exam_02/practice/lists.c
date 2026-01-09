/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:10:20 by diosoare          #+#    #+#             */
/*   Updated: 2026/01/09 11:24:45 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_player
{
	int				id;
	char			name[25];
	struct s_player	*next;
}	t_player;

void	add_front(t_player **head, t_player *new_node)
{
	new_node->next = *head;
	head = new_node;
}

t_player	*new_player(int id, char *name)
{
	t_player	*new_player;
	int			i;

	if (!id || !name)
		return (NULL);
	i = 0;
	new_player = malloc(sizeof(t_player));
	if (!new_player)
		return (NULL);
	while (name[i])
	{
		new_player->name[i] = name[i];
		i++;
	}
	new_player->id = id;
	new_player->next = NULL;
	return (new_player);
}

int	main(void)
{
	t_player	*player1;

	player1 = new_player(1, "Diogo");
	printf("%i - %s\n", player1->id, player1->name);
	free(player1);
	return (0);
}
