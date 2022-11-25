/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:20:56 by samajat           #+#    #+#             */
/*   Updated: 2022/11/25 19:54:44 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


//temp
void draw_rectangle(t_mlx *mlx, t_point point, int COLOR)
{
    int i;
    int j;

    i = 0;
    while (i < ENTITY_SIZE)
    {
        j = 0;
        while (j < ENTITY_SIZE)
        {
            mlx_pixel_put(mlx->mlx, mlx->win, point.X + i, point.Y + j, COLOR);
            j++;
        }
        i++;
    }
}

void draw_line(t_mlx *mlx, const t_point point1, const t_point point2)
{
    int dx = point2.X - point1.X;
    int dy = point2.Y - point1.Y;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    float X = point1.X;
    float Y = point1.Y;
    int i = 0;
    while ( i <= steps)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, X, Y, RED);
        X += Xinc;
        Y += Yinc;
        i++;
    }
}


void    render_grid(t_mlx *mlx)
{
    int y;
    int x;

    y = 0;
    while (y < MAP_COL)
    {
        x = 0;
        while (x < MAP_RAW)
        {
            if (map[y][x] == '1')
                draw_rectangle(mlx, (t_point){.X=x * ENTITY_SIZE,  .Y=y * ENTITY_SIZE}, BLUE);
            // else if (map[y][x] == '0')
            //     draw_rectangle(mlx, (t_point){.X=x * ENTITY_SIZE,  .Y=y * ENTITY_SIZE}, BLA);
            x++;
        }
        y++;
    }
}

void    renderPlayer(t_mlx *mlx, t_player *player)
{
    (void)mlx;(void)player;
    printPlayerData(player);
    // mlx_put_image_to_window(mlx->mlx, mlx->win, player->img,
    //     player->pos.origPoint.X, player->pos.origPoint.Y);
    launch_ray(mlx, &player->pos, player->pos.direction);
}
