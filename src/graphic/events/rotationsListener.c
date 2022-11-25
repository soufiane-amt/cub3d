/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotationsListener.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:06:47 by samajat           #+#    #+#             */
/*   Updated: 2022/11/25 20:11:37 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    turnRight(t_player  *player)
{
    rotatePlayer(player, TO_RIGHT, PLAYER_SPEED);
}

void    turnLeft(t_player  *player)
{
    rotatePlayer(player, TO_LEFT, PLAYER_SPEED);
}

// void    turnUp(t_player  *player)
// {
    
// }

// void    turnDown(t_player  *player)
// {
    
// }