/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_to_default.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:41:33 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 19:03:53 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_mlx *mlx)
{
	mlx->texture.east.img = NULL;
	mlx->texture.west.img = NULL;
	mlx->texture.north.img = NULL;
	mlx->texture.south.img = NULL;
}

void	set_player_default_info(t_player *player, t_parsing *parsing)
{
	player->pos.orig_point = parsing->default_player_data.orig_point;
	player->pos.direction = parsing->default_player_data.direction;
}

void	set_buttons_2_default(t_buttons *buttons)
{
	buttons->da_button = 0;
	buttons->ws_button = 0;
	buttons->rotate_button = 0;
}
