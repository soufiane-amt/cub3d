/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:16:48 by samajat           #+#    #+#             */
/*   Updated: 2022/12/08 17:36:58 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void    put_ground_to_default()
// {
    
// }

void rotatePlayer (t_player *player , int dir, double angleToRotate)
{   
    player->pos.direction = player->pos.direction + (dir * angleToRotate);
}

