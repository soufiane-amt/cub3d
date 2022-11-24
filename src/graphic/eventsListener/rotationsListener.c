/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotationsListener.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:06:47 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 20:37:22 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    turnRight(t_player  *player)
{
    rotatePlayer(player, TO_RIGHT, FOV/2);
}

void    turnLeft(t_player  *player)
{
    rotatePlayer(player, TO_LEFT, FOV/2);
}

// void    turnUp(t_player  *player)
// {
    
// }

// void    turnDown(t_player  *player)
// {
    
// }