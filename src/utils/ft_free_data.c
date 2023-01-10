/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:00:26 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 19:19:27 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_parsing_2_null(t_parsing *parsing)
{
	parsing->map = NULL;
	parsing->no_path = NULL;
	parsing->so_path = NULL;
	parsing->ea_path = NULL;
	parsing->we_path = NULL;
}

void	ft_free_data(t_parsing *parsing, t_param *param)
{
	if (param)
		free(param);
	if (parsing->map)
		free_dub(parsing->map);
	if (parsing->no_path)
		free(parsing->no_path);
	if (parsing->so_path)
		free(parsing->so_path);
	if (parsing->ea_path)
		free(parsing->ea_path);
	if (parsing->we_path)
		free(parsing->we_path);
}

void	ft_exit(t_parsing *parsing, t_param *param)
{
	ft_free_data(parsing, param);
	exit(1);
}

int	exit_game(t_param *param)
{
	if (param->mlx->texture.east.img)
		mlx_destroy_image(param->mlx->mlx, param->mlx->texture.east.img);
	if (param->mlx->texture.west.img)
		mlx_destroy_image(param->mlx->mlx, param->mlx->texture.west.img);
	if (param->mlx->texture.north.img)
		mlx_destroy_image(param->mlx->mlx, param->mlx->texture.north.img);
	if (param->mlx->texture.south.img)
		mlx_destroy_image(param->mlx->mlx, param->mlx->texture.south.img);
	mlx_destroy_window(param->mlx->mlx, param->mlx->win);
	ft_exit(param->parsing, param);
	return (0);
}

int	exit_game_t(t_parsing *parsing, t_mlx *mlx)
{
	if (mlx->texture.east.img)
		mlx_destroy_image(mlx->mlx, mlx->texture.east.img);
	if (mlx->texture.west.img)
		mlx_destroy_image(mlx->mlx, mlx->texture.west.img);
	if (mlx->texture.north.img)
		mlx_destroy_image(mlx->mlx, mlx->texture.north.img);
	if (mlx->texture.south.img)
		mlx_destroy_image(mlx->mlx, mlx->texture.south.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_exit(parsing, NULL);
	return (0);
}
