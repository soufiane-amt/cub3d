/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:41:57 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 18:58:22 by samajat          ###   ########.fr       */
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
    if (!mlx->mlx)
        exit(1);
    mlx->win = mlx_new_window(mlx->mlx, WINDOW_SIZEX, WINDOW_SIZEY, title);
    if (!mlx->win)
        exit(1);
}


void    launch_game(t_mlx *mlx)
{
    // t_vector vector = {.origPoint = (t_point){500, 500}, -90, 200};

    // launch_ray(mlx, &vector , -90 );
    render_grid(mlx);
    // mlx_
}

int main ()
{
    t_mlx   mlx;

    set_up_mlx(&mlx, "cub3d");
    launch_game(&mlx);
    keep_game_working(&mlx);
}