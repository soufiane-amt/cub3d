/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesListener.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:04 by samajat           #+#    #+#             */
/*   Updated: 2022/12/02 14:45:34 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int     move_is_valid (t_point  dstPoint)
{
    int x;
    int y;

    x = dstPoint.X/ENTITY_SIZE;    
    y = dstPoint.Y/ENTITY_SIZE;
    if (map[y][x] != '1')
        return (1);
    return 0;
}

// void    moveLeft(t_player  *player)
// {
//     t_point dstPoint;

//     dstPoint.X = player->pos.origPoint.X - PLAYER_SPEED;
//     dstPoint.Y = player->pos.origPoint.Y;
//     if (move_is_valid(dstPoint))
//         player->pos.origPoint.X-=PLAYER_SPEED;
// }
// void    moveRight(t_player  *player)
// {
//     t_point dstPoint;

//     dstPoint.X = player->pos.origPoint.X + PLAYER_SPEED;
//     dstPoint.Y = player->pos.origPoint.Y;
//     if (move_is_valid(dstPoint))
//         player->pos.origPoint.X+=PLAYER_SPEED;
// }
// void    moveFront(t_player  *player)
// {
//     t_point dstPoint;

//     dstPoint.X = player->pos.origPoint.X;
//     dstPoint.Y = player->pos.origPoint.Y - PLAYER_SPEED;
//     if (move_is_valid(dstPoint))
//         player->pos.origPoint.Y-=PLAYER_SPEED;
// }

// void    moveBack(t_player  *player)
// {
//     t_point dstPoint;

//     dstPoint.X = player->pos.origPoint.X;
//     dstPoint.Y = player->pos.origPoint.Y + PLAYER_SPEED;
//     if (move_is_valid(dstPoint))
//         player->pos.origPoint.Y+=PLAYER_SPEED;
// }
void    moveLeft(t_player  *player)
{
    // t_point dstPoint;
    float   radian;

    radian = convert_degree_to_radian(player->pos.direction + 90);
    player->pos.origPoint.X -= (PLAYER_SPEED * cos(radian));
    player->pos.origPoint.Y -= (PLAYER_SPEED * sin(radian));
}
void    moveRight(t_player  *player)
{
    float   radian;

    radian = convert_degree_to_radian(player->pos.direction + 90);
    player->pos.origPoint.X += (PLAYER_SPEED * cos(radian));
    player->pos.origPoint.Y += (PLAYER_SPEED * sin(radian));
}

void    moveBack(t_player  *player)
{
    float   radian;

    radian = convert_degree_to_radian(player->pos.direction);
    player->pos.origPoint.X -= (PLAYER_SPEED * cos(radian));
    player->pos.origPoint.Y -= (PLAYER_SPEED * sin(radian));
}

void    moveFront(t_player  *player)
{
    float   radian;

    radian = convert_degree_to_radian(player->pos.direction);
    player->pos.origPoint.X += (PLAYER_SPEED * cos(radian));
    player->pos.origPoint.Y += (PLAYER_SPEED * sin(radian));
}