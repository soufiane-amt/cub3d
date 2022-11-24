/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesListener.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:04 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 22:20:47 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    moveLeft(t_player  *player)
{
    player->pos.origPoint.X--;
}
void    moveRight(t_player  *player)
{
    player->pos.origPoint.X++;
}

void    moveFront(t_player  *player)
{
    player->pos.origPoint.Y--;

}

void    moveBack(t_player  *player)
{
    player->pos.origPoint.Y++;
}