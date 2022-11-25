/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesListener.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:04 by samajat           #+#    #+#             */
/*   Updated: 2022/11/25 20:06:44 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    moveLeft(t_player  *player)
{
    player->pos.origPoint.X-=PLAYER_SPEED;
}
void    moveRight(t_player  *player)
{
    player->pos.origPoint.X+=PLAYER_SPEED;
}

void    moveFront(t_player  *player)
{
    player->pos.origPoint.Y-=PLAYER_SPEED;

}

void    moveBack(t_player  *player)
{
    player->pos.origPoint.Y+=PLAYER_SPEED;
}