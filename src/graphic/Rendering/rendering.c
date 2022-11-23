/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:20:56 by samajat           #+#    #+#             */
/*   Updated: 2022/11/23 21:33:37 by samajat          ###   ########.fr       */
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
void draw_rectangle(void *mlx, void *win, int x, int y)
{
    int i = 0;
    int j;

    j = 0;
    while (i < ENTITY_SIZE)
    {
        j = 0;
        while (j < ENTITY_SIZE)
        {
            mlx_pixel_put(mlx, win, x + j, y + i, BLUE);
            j++;
        }
        i++;
    }
}

void draw_line(t_mlx *mlx, const t_point *point1, const t_point *point2)
{
    // calculate dx & dy
    int dx = point2->X - point1->X;
    int dy = point2->Y - point1->Y;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    // Put pixel for each step
    float X = point1->X;
    float Y = point1->Y;
    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(mlx.mlx, mlx.win, X, Y, RED); // put pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
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
                draw_rectangle(mlx->mlx, mlx->win, i * ENTITY_SIZE, j * ENTITY_SIZE);
            j++;
        }
        i++;
    }
}