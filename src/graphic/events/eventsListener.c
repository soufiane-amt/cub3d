/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventsListener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:18:31 by samajat           #+#    #+#             */
/*   Updated: 2022/12/02 13:26:14 by samajat          ###   ########.fr       */
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
    return (0);
}

void    reform_map(t_mlx *mlx, t_player *player)
{
    mlx_clear_window(mlx->mlx, mlx->win);
    mlx_destroy_image(mlx->mlx, mlx->img.img);
    mlx->img = ft_creat_an_image(mlx);
    render_grid(mlx);
    renderPlayer(mlx, player);
}


int events_catcher(int keyCode, t_param *param)
{
    key_press(keyCode, param->player);
    reform_map(param->mlx, param->player);
    return (0);
}

void    eventPerceiver(t_mlx *mlx, t_player *player)
{
    t_param *param = malloc(sizeof(t_param *));
    
    param->mlx = mlx;
    param->player = player;
    mlx_hook(mlx->win, 2, 0, events_catcher, param);
    //param is to be freed at the exit
}