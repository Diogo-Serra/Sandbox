/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:38:37 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/15 14:54:32 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	main(void)
{
	t_player	*player1;

	printf("Teste\n");
	player1 = create_player(1, 50, "Player1");
	printf("%d\n%s\n%d", player1->id, player1->name, player1->score);
	printf("\n");
	free(player1);
	return (0);
}
