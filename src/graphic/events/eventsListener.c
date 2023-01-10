/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventsListener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:18:31 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 15:19:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reform_graphic(t_mlx *mlx, t_player *player, t_parsing *parsing)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx->img = ft_creat_an_image(mlx);
	project_3d(mlx, player, parsing);
}

int	press_key(int keyCode, t_param *param)
{
	if (keyCode == MOVE_LEFT_KEY)
		param->buttons.da_button = -1;
	else if (keyCode == MOVE_RIGHT_KEY)
		param->buttons.da_button = 1;
	else if (keyCode == MOVE_FRONT_KEY)
		param->buttons.ws_button = 1;
	else if (keyCode == MOVE_BACK_KEY)
		param->buttons.ws_button = -1;
	else if (keyCode == TURN_LEFT_KEY)
		param->buttons.rotate_button = -1;
	else if (keyCode == TURN_RIGHT_KEY)
		param->buttons.rotate_button = 1;
	else if (keyCode == ESC)
		exit_game(param);
	return (0);
}

int	release(int keyCode, t_param *param)
{
	if (keyCode == MOVE_LEFT_KEY)
		param->buttons.da_button = 0;
	else if (keyCode == MOVE_RIGHT_KEY)
		param->buttons.da_button = 0;
	else if (keyCode == MOVE_FRONT_KEY)
		param->buttons.ws_button = 0;
	else if (keyCode == MOVE_BACK_KEY)
		param->buttons.ws_button = 0;
	else if (keyCode == TURN_LEFT_KEY)
		param->buttons.rotate_button = 0;
	else if (keyCode == TURN_RIGHT_KEY)
		param->buttons.rotate_button = 0;
	return (0);
}

int	render(t_param *parm)
{
	parm->player->pos.direction = angle_normalizer(parm->player->pos.direction
			+ (PLAYER_SPEED / 4) * parm->buttons.rotate_button);
	update_ad_buttons (parm);
	update_ws_buttons (parm);
	reform_graphic(parm->mlx, parm->player, parm->parsing);
	return (0);
}

void	event_perceiver(t_mlx *mlx, t_player *player, t_parsing *parsing)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		ft_exit(parsing, NULL);
	param->mlx = mlx;
	param->player = player;
	param->parsing = parsing;
	set_buttons_2_default(&param->buttons);
	mlx_loop_hook(mlx->mlx, render, param);
	mlx_hook(mlx->win, 3, 0, release, param);
	mlx_hook(mlx->win, 2, 0, press_key, param);
	mlx_hook(mlx->win, 6, 0, mouse_move, param);
	mlx_hook(mlx->win, 17, 0, exit_game, param);
}
