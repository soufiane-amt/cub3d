/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesListener.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:04 by samajat           #+#    #+#             */
/*   Updated: 2022/12/05 19:50:56 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int     point_is_not_a_wall (t_point  dstPoint)
{
    int x;
    int y;

    x = dstPoint.X/ENTITY_SIZE;
    y = dstPoint.Y/ENTITY_SIZE;
    if (y <= MAP_COL && x <= MAP_RAW && map[y][x] != '1')
        return (1);
    return 0;
}

void    moveLeft(t_player  *player)
{
    t_point dstPoint;
    float   radianValue;

    radianValue = convert_degree_to_radian(player->pos.direction + 90);
    dstPoint.X = player->pos.origPoint.X - (PLAYER_SPEED * cos(radianValue));
    dstPoint.Y = player->pos.origPoint.Y - (PLAYER_SPEED * sin(radianValue));
    if (point_is_not_a_wall(dstPoint))
    {
        player->pos.origPoint.X -= (PLAYER_SPEED * cos(radianValue));
        player->pos.origPoint.Y -= (PLAYER_SPEED * sin(radianValue));
    }
}

void    moveRight(t_player  *player)
{
    t_point dstPoint;
    float   radianValue;

    radianValue = convert_degree_to_radian(player->pos.direction + 90);
    dstPoint.X = player->pos.origPoint.X + (PLAYER_SPEED * cos(radianValue));
    dstPoint.Y = player->pos.origPoint.Y + (PLAYER_SPEED * sin(radianValue));
    if (point_is_not_a_wall((dstPoint)))
    {
        player->pos.origPoint.X += (PLAYER_SPEED * cos(radianValue));
        player->pos.origPoint.Y += (PLAYER_SPEED * sin(radianValue));
    }
}

void    moveBack(t_player  *player)
{
    t_point dstPoint;
    float   radianValue;

    radianValue = convert_degree_to_radian(player->pos.direction);
    dstPoint.X = player->pos.origPoint.X - (PLAYER_SPEED * cos(radianValue));
    dstPoint.Y = player->pos.origPoint.Y - (PLAYER_SPEED * sin(radianValue));
    if (point_is_not_a_wall((dstPoint)))
    {
        player->pos.origPoint.X -= (PLAYER_SPEED * cos(radianValue));
        player->pos.origPoint.Y -= (PLAYER_SPEED * sin(radianValue));
    }
}

void    moveFront(t_player  *player)
{
    t_point dstPoint;
    float   radianValue;

    radianValue = convert_degree_to_radian(player->pos.direction);
    dstPoint.X = player->pos.origPoint.X + (PLAYER_SPEED * cos(radianValue));
    dstPoint.Y = player->pos.origPoint.Y + (PLAYER_SPEED * sin(radianValue));
    if (point_is_not_a_wall((dstPoint)))
    {
        player->pos.origPoint.X += (PLAYER_SPEED * cos(radianValue));
        player->pos.origPoint.Y += (PLAYER_SPEED * sin(radianValue));
    }
}