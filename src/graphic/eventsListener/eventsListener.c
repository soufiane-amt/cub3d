/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventsListener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:18:31 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 20:11:04 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//A function implemented to respond to user Actions (events)

int     key_press(int keyCode, t_player *player)
{
    if (keyCode == MOVE_LEFT_KEY)
        moveLeft(player);
    else if (keyCode == MOVE_RIGHT_KEY)
        moveRight(player);
    else if (keyCode == MOVE_FRONT_KEY)
        moveFront(player);
    else if (keyCode == MOVE_BACK_KEY)
        moveBack(player);
	else if (keyCode == TURN_LEFT_KEY)
        turnLeft(player);
	else if (keyCode == TURN_RIGHT_KEY)
        turnRight(player);
	else if (keyCode == TURN_UP_KEY)
        turnUp(player);
	else if (keyCode == TURN_DOWN_KEY)
        turnDown(player);
}

void    eventPerceiver(t_mlx *mlx, t_player *player)
{
    mlx_hook(mlx->win, 2, 0, key_press, player)
}