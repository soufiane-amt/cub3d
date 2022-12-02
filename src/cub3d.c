/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:41:57 by samajat           #+#    #+#             */
/*   Updated: 2022/12/02 20:56:27 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char map[MAP_COL][MAP_RAW] = {{'1', '1', '1', '1', '1', '1', '1'},
//                               {'1', '0', '0', '0', '0', '0', '1'},
//                               {'1', '0', '0', '0', '0', '0', '1'},
//                               {'1', '0', '1', '0', '0', '0', '1'},
//                               {'1', '0', '0', '0', '0', '0', '1'},
//                               {'1', '0', '0', '0', '0', '0', '1'},
//                               {'1', '0', '0', '0', 'N', '0', '1'},
//                               {'1', '1', '1', '1', '1', '1', '1'}};
char map[MAP_COL][MAP_RAW] = {{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','0','0','0','0','0','0'},
                             { '1','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0'},
                             { '1','0','1','1','0','0','0','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0'},
                             { '1','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0'},
                             { '1','1','1','1','1','1','1','1','1','0','1','1','0','0','0','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
                             { '1','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1'},
                             { '1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0'},
                             { '1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','1','0','1','0','0','1','0','0','0','1','0','0','0','0'},
                             { '1','1','0','0','0','0','0','0','1','1','0','1','0','1','0','1','1','1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0'},
                             { '1','0','0','0','0','0','0','0','0','0','0','N','0','0','0','0','1','1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0'},
                             { '1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','0','1','0','1','0','0','1','0','0','0','1','0','0','0','0'},
                             { '1','1','0','0','0','0','0','1','1','1','0','1','0','1','0','1','1','1','1','1','0','1','1','1','1','0','0','0','1','1','1','0','0'},
                             { '1','1','1','1','0','1','1','1','1','1','1','0','1','0','1','1','0','1','1','1','1','0','1','0','0','0','1','0','0','0','0','0','0'},
                             { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','0','0','0','0'}};
int    printPlayerData(t_player *player)
{
    printf("Player vector :\n");
    printf("Player X : %d\n", player->pos.origPoint.X);
    printf("Player Y : %d\n", player->pos.origPoint.Y);
    printf("Player magnitude : %f\n", player->pos.magnitude);
    printf("Player Direction : %f\n", player->pos.direction);
    return 0;
}

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
    mlx->img = ft_creat_an_image(mlx);
}

void    launch_game(t_mlx *mlx)
{
    t_player    player;

    set_player_default_info(mlx, &player);
    render_grid(mlx);
    renderPlayer(mlx, &player);
    eventPerceiver(mlx, &player);
    keep_game_working(mlx);
}

int main ()
{
    t_mlx   mlx;

    set_up_mlx(&mlx, "cub3d");
    launch_game(&mlx);
}
