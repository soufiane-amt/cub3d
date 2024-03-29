/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotationsListener.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:06:47 by samajat           #+#    #+#             */
/*   Updated: 2023/01/03 17:01:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player, int dir, double angleToRotate)
{
	player->pos.direction = angle_normalizer(player->pos.direction + (dir
				* angleToRotate));
}

void	turn_right(t_player *player)
{
	rotate_player(player, TO_RIGHT, PLAYER_SPEED / 2);
}

void	turn_left(t_player *player)
{
	rotate_player(player, TO_LEFT, PLAYER_SPEED / 2);
}
