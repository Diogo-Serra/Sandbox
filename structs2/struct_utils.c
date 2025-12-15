/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:44:13 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/15 16:42:14 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_player	*create_player(int id, int score, char *name)
{
	t_player	*new_player;
	int			i;

	new_player->id = id;
	new_player->score = score;
	new_player->next = NULL;
	i = 0;
	while (name[i])
	{
		new_player->name[i] = name[i];
		i++;
	}
	new_player->name[i] = '\0';
	return (new_player);
}
