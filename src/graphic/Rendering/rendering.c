/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:20:56 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 20:39:49 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char map[MAP_COL][MAP_RAW] = {{'1', '1', '1', '1', '1', '1', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '1', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', 'N', '0', '1'},
                {'1', '1', '1', '1', '1', '1', '1'}};

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
            mlx_pixel_put(mlx->mlx, mlx->win, point.X + j, point.Y + i, COLOR);
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
    int i;
    int j;

    i = 0;
    while (i < MAP_COL)
    {
        j = 0;
        while (j < MAP_RAW)
        {
            if (map[i][j] == '1')
                draw_rectangle(mlx, (t_point){.X=i * ENTITY_SIZE,  .Y=j * ENTITY_SIZE}, BLUE);
            else if (map[i][j] == '0')
                draw_rectangle(mlx, (t_point){.X=i * ENTITY_SIZE,  .Y=j * ENTITY_SIZE}, BLACK);
            j++;
        }
        i++;
    }
}

void    renderPlayer(t_mlx *mlx, t_player *player)
{
    
}
