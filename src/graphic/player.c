/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:16:48 by samajat           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/08 14:35:14 by samajat          ###   ########.fr       */
=======
/*   Updated: 2022/12/05 20:39:37 by samajat          ###   ########.fr       */
>>>>>>> 8c484749fc23c2d5abc8c25af6fa879f911b9712
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void    put_ground_to_default()
// {
    
// }

void rotatePlayer (t_player *player , int dir, double angleToRotate)
<<<<<<< HEAD
{   
    player->pos.direction = player->pos.direction + (dir * angleToRotate);
=======
{
    if (player->pos.direction <= -180)
        player->pos.direction = 180;
    player->pos.direction = player->pos.direction + (dir * angleToRotate) * 10000000000;
>>>>>>> 8c484749fc23c2d5abc8c25af6fa879f911b9712
}

