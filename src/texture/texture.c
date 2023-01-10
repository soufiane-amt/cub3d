/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:47:52 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 19:35:45 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_x(const t_ray *ray)
{
	int	column_x;

	if (ray->intersect_is_vertical)
		column_x = (int)ray->intersect_point.y % TILE_SIZE;
	if (!ray->intersect_is_vertical)
		column_x = (int)ray->intersect_point.x % TILE_SIZE;
	return (column_x);
}

t_img	get_fitting_texture(const t_mlx *mlx, const t_ray *ray)
{
	if (ray->intersect_is_vertical && ray->is_right)
		return (mlx->texture.east);
	else if (ray->intersect_is_vertical && !ray->is_right)
		return (mlx->texture.west);
	else if (!ray->intersect_is_vertical && ray->is_up)
		return (mlx->texture.north);
	return (mlx->texture.south);
}

int	get_texture_pixel_color(const t_img *texture, t_point point)
{
	return (*(int *)(texture->addr
		+ ((int)point.y * texture->line_len + (int)point.x
			* (texture->bpp / 8))));
}

void	draw_texture_line(t_mlx *mlx, t_point win_point, const t_ray *ray,
		double height)
{
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	t_img	fitting_texture;
	int		distance;
	int		texture_offset_y;

	wall_top_pixel = win_point.y;
	wall_bottom_pixel = win_point.y + height;
	fitting_texture = get_fitting_texture(mlx, ray);
	while (wall_top_pixel < wall_bottom_pixel)
	{
		distance = wall_top_pixel - (WINDOW_HEIGHT / 2) + (height / 2);
		texture_offset_y = distance * ((double)fitting_texture.height / height);
		my_mlx_pixel_put(&mlx->img, win_point.x, wall_top_pixel,
			get_texture_pixel_color(&fitting_texture,
				(t_point){get_texture_x(ray), texture_offset_y}));
		wall_top_pixel++;
	}
}

void	*set_up_texture(t_mlx *mlx, t_parsing *parsing)
{
	init_texture(mlx);
	set_no_eas_text(mlx, parsing);
	set_we_so_text(mlx, parsing);
	return ((void *)1);
}
