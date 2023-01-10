/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:29:18 by samajat           #+#    #+#             */
/*   Updated: 2023/01/04 19:25:53 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_ws_buttons(t_param	*param)
{
	int		step;
	t_point	player_update;

	if (param->buttons.ws_button)
	{
		step = (PLAYER_SPEED) * param->buttons.ws_button;
		player_update.x = param->player->pos.orig_point.x
			+ ft_cos(param->player->pos.direction) * step;
		player_update.y = param->player->pos.orig_point.y
			+ ft_sin(param->player->pos.direction) * step;
		if (point_is_not_a_wall(player_update, param->parsing))
		{
			param->player->pos.orig_point.x = player_update.x;
			param->player->pos.orig_point.y = player_update.y;
		}
	}
}

void	update_ad_buttons(t_param	*param)
{
	int		step;
	t_point	player_update;

	if (param->buttons.da_button)
	{
		step = (PLAYER_SPEED) * param->buttons.da_button;
		player_update.x = param->player->pos.orig_point.x
			+ ft_cos(param->player->pos.direction + 90) * step;
		player_update.y = param->player->pos.orig_point.y
			+ ft_sin(param->player->pos.direction + 90) * step;
		if (point_is_not_a_wall(player_update, param->parsing))
		{
			param->player->pos.orig_point.x = player_update.x;
			param->player->pos.orig_point.y = player_update.y;
		}
	}
}
