/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:42:02 by samajat           #+#    #+#             */
/*   Updated: 2022/11/17 23:47:34 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

#define RED 0xff0000

void draw_rectangle(void *mlx, void *win)
{
    int i = 0;
    int j;

    j = 0;
    while (i < 100)
    {
        j = 0;
        while (j < 100)
        {
            mlx_pixel_put(mlx, win, 500 + j, 500 + i, RED);
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
        mlx_pixel_put(mlx, win, x + i, y, RED);
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
        draw_line(mlx, win , 500 - i, 500 - i,  i * 2 );
        i++;
    }
}

int main ()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "TEST");
    // draw_line(mlx, win, 500, 500, 100);
    draw_triangle(mlx, win);
    mlx_loop(mlx);
}