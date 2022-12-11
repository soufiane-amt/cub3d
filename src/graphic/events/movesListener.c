/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesListener.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:04 by samajat           #+#    #+#             */
/*   Updated: 2022/12/11 15:45:37 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int within_wall(int x, int y)
{
    return ((x >= 0 && x <= WINDOW_SIZEX ) && (y >= 0 && y <= WINDOW_SIZEY));
}

int     point_is_not_a_wall (t_point  dstPoint)
{
    int x;
    int y;

    x = dstPoint.X/ENTITY_SIZE;
    y = dstPoint.Y/ENTITY_SIZE;
    if (!(within_wall(x, y)) || map[y][x] == '1')
        return (0);
    printf("<----------->\n");
    return (1);
}

void    moveLeft(t_player  *player)
{
    t_point dstPoint;
    float   radianValue;

    radianValue = convert_degree_to_radian(player->pos.direction + 90);
    dstPoint.X = roundf(player->pos.origPoint.X - (PLAYER_SPEED * cos(radianValue)));
    dstPoint.Y = roundf(player->pos.origPoint.Y - (PLAYER_SPEED * sin(radianValue)));
    if (point_is_not_a_wall(dstPoint))
    {
        player->pos.origPoint.X -= roundf((PLAYER_SPEED * cos(radianValue)));
        player->pos.origPoint.Y -= roundf((PLAYER_SPEED * sin(radianValue)));
    }
}

void    moveRight(t_player  *player)
{
    t_point dstPoint;
    float   radianValue;

    radianValue = convert_degree_to_radian(player->pos.direction + 90);
    dstPoint.X = roundf(player->pos.origPoint.X + (PLAYER_SPEED * cos(radianValue)));
    dstPoint.Y = roundf(player->pos.origPoint.Y + (PLAYER_SPEED * sin(radianValue)));
    if (point_is_not_a_wall((dstPoint)))
    {
        player->pos.origPoint.X += roundf((PLAYER_SPEED * cos(radianValue)));
        player->pos.origPoint.Y += roundf((PLAYER_SPEED * sin(radianValue)));
    }
}

void    moveBack(t_player  *player)
{
    t_point dstPoint;
    float   radianValue;

    radianValue = convert_degree_to_radian(player->pos.direction);
    dstPoint.X = roundf(player->pos.origPoint.X - (PLAYER_SPEED * cos(radianValue)));
    dstPoint.Y = roundf(player->pos.origPoint.Y - (PLAYER_SPEED * sin(radianValue)));
    if (point_is_not_a_wall((dstPoint)))
    {
        player->pos.origPoint.X -=roundf( (PLAYER_SPEED * cos(radianValue)));
        player->pos.origPoint.Y -=roundf( (PLAYER_SPEED * sin(radianValue)));
    }
}

void    moveFront(t_player  *player)
{
    t_point dstPoint;
    float   radianValue;

    radianValue = convert_degree_to_radian(player->pos.direction);
    dstPoint.X = roundf(player->pos.origPoint.X + (PLAYER_SPEED * cos(radianValue)));
    dstPoint.Y = roundf(player->pos.origPoint.Y + (PLAYER_SPEED * sin(radianValue)));
    if (point_is_not_a_wall((dstPoint)))
    {
        player->pos.origPoint.X += roundf((PLAYER_SPEED * cos(radianValue)));
        player->pos.origPoint.Y += roundf((PLAYER_SPEED * sin(radianValue)));
    }
}