/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_to_default.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:41:33 by samajat           #+#    #+#             */
/*   Updated: 2022/12/18 21:14:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_point get_player_coordinates ()
{
    int y;
    int x;

    y = 1;
    while (y < MAP_COL)
    {
        x = 1;
        while (x < MAP_RAW)
        {
            if (map[y][x] == 'N')
                return ((t_point){.X=x * ENTITY_SIZE , .Y=y * ENTITY_SIZE });
            x++;
        }
        y++;
    }
    return ((t_point){.X=x * ENTITY_SIZE , .Y=y * ENTITY_SIZE });
}

void    set_player_default_info(t_mlx *mlx, t_player *player)
{
    // int dimensions;

    // dimensions = ENTITY_SIZE;
    (void)mlx;
    player->pos.origPoint = get_player_coordinates();
    player->pos.direction = 90;
    player->pos.magnitude = RAY_LENGTH;
    // player->img = mlx_xpm_file_to_image(mlx->mlx, AVATAR_IMG, &dimensions, &dimensions);
} 