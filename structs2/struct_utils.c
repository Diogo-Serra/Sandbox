/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:44:13 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/13 17:16:15 by diosoare         ###   ########.fr       */
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
	return (player);
}
