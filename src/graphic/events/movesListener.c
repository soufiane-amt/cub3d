/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesListener.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:04 by samajat           #+#    #+#             */
/*   Updated: 2022/11/25 11:19:14 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    moveLeft(t_player  *player)
{
    player->pos.origPoint.X -= ENTITY_SIZE;
}
void    moveRight(t_player  *player)
{
    player->pos.origPoint.X += ENTITY_SIZE;
}

void    moveFront(t_player  *player)
{
    player->pos.origPoint.Y -= ENTITY_SIZE;

}

void    moveBack(t_player  *player)
{
    player->pos.origPoint.Y += ENTITY_SIZE;
}