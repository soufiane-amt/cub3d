/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:42:02 by samajat           #+#    #+#             */
/*   Updated: 2022/11/18 13:35:15 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

#define RED 0xff0000
#define BLUE 255
#define GREEN 0x0000FF00

#define MAP_RAW 7
#define MAP_COL 8
#define ENTITY_SIZE 50

char map[MAP_COL][MAP_RAW] = {{'1', '1', '1', '1', '1', '1', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '1', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '1', '1', '1', '1', '1', '1'}};
                
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

void draw_line(void *mlx, void *win, int x, int y, int length)
{
    int i;

    i = 0;
    while (i < length)
    {
           mlx_pixel_put(mlx, win, x + i, y, i);
        i++;
    }
}
void draw_triangle(void *mlx, void *win)
{
    int i = 0;
    int position = 500;
    int j;

    while (i <= 100)
    {
        if (i % 2)
        {
            draw_line(mlx, win , 500 - i, 500 - i,  i * 2);
        }
        i++;
    }
}


void draw_all(void *mlx, void *win)
{
    int i = 0;

    while (i <= 400)
    {
        if (i % 2)
        {
            draw_line(mlx, win , 500 - i, 500 - i,  i * 2);
        }
        i++;
    }
}

void    rendering_map(void *mlx, void *win)
{
    int i = 0;
    while (i < MAP_COL)
    {
        int j = 0;
        while (j < MAP_RAW)
        {
            if (map[i][j] == '1')
                draw_rectangle(mlx, win, i * ENTITY_SIZE, j * ENTITY_SIZE);
            j++;
        }
        i++;
    }
    
}

int main ()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "TEST");
    rendering_map(mlx, win);
    mlx_loop(mlx);
}