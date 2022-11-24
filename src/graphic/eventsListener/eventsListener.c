/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventsListener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:18:31 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 21:27:03 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//A function implemented to respond to user Actions (events)


int     key_press(int keyCode, void *p)
{
    t_param *param;

    param = (t_param *)p;
    if (keyCode == MOVE_LEFT_KEY)
        moveLeft(param->player);
    else if (keyCode == MOVE_RIGHT_KEY)
        moveRight(param->player);
    else if (keyCode == MOVE_FRONT_KEY)
        moveFront(param->player);
    else if (keyCode == MOVE_BACK_KEY)
        moveBack(param->player);
	else if (keyCode == TURN_LEFT_KEY)
        turnLeft(param->player);
	else if (keyCode == TURN_RIGHT_KEY)
        turnRight(param->player);
	// else if (keyCode == TURN_UP_KEY)
    //     turnUp(player);
	// else if (keyCode == TURN_DOWN_KEY)
    //     turnDown(player);
    render_grid(param->mlx);
    renderPlayer(param->mlx, param->player);
}

void    eventPerceiver(t_mlx *mlx, t_player *player)
{
    mlx_hook(mlx->win, 2, 0, key_press, (&));
}