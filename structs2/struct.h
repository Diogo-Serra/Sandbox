/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosoare <diosoare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:36:23 by diosoare          #+#    #+#             */
/*   Updated: 2025/12/13 17:07:13 by diosoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_player
{
	int		id;
	int		score;
	char	name[50];	
}	t_player;

t_player	create_player(int id, int score, char *name);

#endif /* STRUCT_H */