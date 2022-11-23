/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:41:57 by samajat           #+#    #+#             */
/*   Updated: 2022/11/23 22:44:21 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    keep_game_working(t_mlx *mlx)
{
    mlx_loop(mlx->mlx);
}

void    set_up_mlx(t_mlx    *mlx, char* title)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, WINDOW_SIZEX, WINDOW_SIZEY, title);
}


void    launch_game(t_mlx *mlx)
{
    // render_grid(mlx);
    t_vector vector = {.origPoint = (t_point){500, 500}, .dirPoint = (t_point){700, 500}, 0, 100};
    draw_line(mlx, vector.origPoint,  vector.dirPoint);
    int i = 0;
    while (i < 8)
    {
        rotate(mlx, &vector , i * (-45) );
        i++;
    }
    
}

int main ()
{
    t_mlx   mlx;

    set_up_mlx(&mlx, "cub3d");
    launch_game(&mlx);
    keep_game_working(&mlx);
}