/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:16:48 by samajat           #+#    #+#             */
/*   Updated: 2022/12/15 17:36:15 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void    put_ground_to_default()
// {
    
// }
void rotatePlayer (t_player *player , int dir, double angleToRotate)
{
    player->pos.direction = player->pos.direction + (dir * angleToRotate);
    // if (player->pos.direction < -180)
    //     player->pos.direction = (player->pos.direction + 360);
    // if (player->pos.direction > 180) 
    //     player->pos.direction = (player->pos.direction - 360);
    if (player->pos.direction >= 360 )
        player->pos.direction = 0;
    if (player->pos.direction < 0 )
        player->pos.direction = 360;
}

