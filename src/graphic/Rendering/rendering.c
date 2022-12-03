/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:20:56 by samajat           #+#    #+#             */
/*   Updated: 2022/12/03 22:53:51 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
            x++;
        }
        y++;
    }
}


void    renderPlayer(t_mlx *mlx, t_player *player)
{
    (void)mlx;(void)player;
    printPlayerData(player);
    launch_ray(mlx, &player->pos, 0);
    // fire_rays(mlx, &player->pos);
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
