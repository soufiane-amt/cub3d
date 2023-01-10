/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:41:57 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 19:21:48 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keep_game_working(t_mlx *mlx)
{
	mlx_loop(mlx->mlx);
}

void	set_up_mlx(t_mlx *mlx, char *title, t_parsing *parsing)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(1);
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, title);
	if (!mlx->win)
		exit(1);
	mlx->img = ft_creat_an_image(mlx);
	if (!set_up_texture(mlx, parsing))
		exit_game_t(parsing, mlx);
}

void	parse_file(int ac, char **argv, t_parsing *parsing)
{
	if (ft_parser(ac, argv, parsing))
		ft_exit(parsing, NULL);
}

void	launch_game(t_mlx *mlx, t_parsing *parsing)
{
	t_player	player;

	set_player_default_info(&player, parsing);
	project_3d(mlx, &player, parsing);
	event_perceiver(mlx, &player, parsing);
	keep_game_working(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_parsing	parsing;

	parse_file(argc, argv, &parsing);
	set_up_mlx(&mlx, "cub3d", &parsing);
	launch_game(&mlx, &parsing);
	return (0);
}
