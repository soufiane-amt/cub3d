/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:29:57 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 19:34:41 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*set_no_eas_text(t_mlx *mlx, t_parsing *parsing)
{
	mlx->texture.north.img = mlx_xpm_file_to_image(mlx->mlx, parsing->no_path,
			&mlx->texture.north.width, &mlx->texture.north.height);
	if (!mlx->texture.north.img)
		return (NULL);
	mlx->texture.north.addr = mlx_get_data_addr(mlx->texture.north.img,
			&mlx->texture.north.bpp, &mlx->texture.north.line_len,
			&mlx->texture.north.endian);
	mlx->texture.east.img = mlx_xpm_file_to_image(mlx->mlx, parsing->ea_path,
			&mlx->texture.east.width, &mlx->texture.east.height);
	if (!mlx->texture.east.img)
		return (NULL);
	mlx->texture.east.addr = mlx_get_data_addr(mlx->texture.east.img,
			&mlx->texture.east.bpp, &mlx->texture.east.line_len,
			&mlx->texture.east.endian);
	return ((void *)1);
}

void	*set_we_so_text(t_mlx *mlx, t_parsing *parsing)
{
	mlx->texture.west.img = mlx_xpm_file_to_image(mlx->mlx, parsing->we_path,
			&mlx->texture.west.width, &mlx->texture.west.height);
	if (!mlx->texture.west.img)
		return (NULL);
	mlx->texture.west.addr = mlx_get_data_addr(mlx->texture.west.img,
			&mlx->texture.west.bpp, &mlx->texture.west.line_len,
			&mlx->texture.west.endian);
	mlx->texture.south.img = mlx_xpm_file_to_image(mlx->mlx, parsing->so_path,
			&mlx->texture.south.width, &mlx->texture.south.height);
	if (!mlx->texture.south.img)
		return (NULL);
	mlx->texture.south.addr = mlx_get_data_addr(mlx->texture.south.img,
			&mlx->texture.south.bpp, &mlx->texture.south.line_len,
			&mlx->texture.south.endian);
	return ((void *)1);
}
