/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_to_default.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:41:33 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 23:48:02 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_point get_player_coordinates ()
{
    int i;
    int j;

    i = 0;
    while (i < MAP_COL)
    {
        j = 0;
        while (j < MAP_RAW)
        {
            if (map[i][j] == 'N')
                break;
            j++;
        }
        i++;
    }
    return ((t_point){i, j});
}

void    set_player_default_info(t_mlx *mlx, t_player *player)
{
    player->pos.origPoint = get_player_coordinates();
    player->pos.direction = 90;
    player->pos.magnitude = RAY_LENGTH;
    player->img = mlx_xpm_file_to_image(mlx->mlx, AVATAR_IMG, &player->pos.origPoint.X, &player->pos.ori)
}