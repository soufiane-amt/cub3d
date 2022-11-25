/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventsListener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:18:31 by samajat           #+#    #+#             */
/*   Updated: 2022/11/25 17:29:16 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//A function implemented to respond to user Actions (events)


	// else if (keyCode == TURN_UP_KEY)
    //     turnUp(player);
	// else if (keyCode == TURN_DOWN_KEY)
    //     turnDown(player);
    
int     key_press(int keyCode, t_param *p)
{
    t_param *param;

    param = (t_param *)p;
    printf("How it's been catched :%p\n", param->mlx->win);
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
    mlx_clear_window(param->mlx->mlx, param->mlx->win);
    // render_grid(param->mlx);
    // renderPlayer(param->mlx, param->player);
    return (0);
}

void    eventPerceiver(t_mlx *mlx, t_player *player)
{
    t_param param;

    param.mlx = mlx;
    param.player = player;
    printf("How it should be :%p\n", mlx->win);
    mlx_hook(mlx->win, 2, (0L), key_press, &param);
}