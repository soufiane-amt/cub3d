/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project3dReality.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:56:38 by samajat           #+#    #+#             */
/*   Updated: 2023/01/05 21:18:01 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_ceil_ground(t_mlx *mlx, t_parsing *parsing)
{
	int	ceil;
	int	floor;
	int	x;
	int	y;

	x = -1;
	y = 0;
	ceil = create_trgb(parsing->ceiling[0], parsing->ceiling[1],
			parsing->ceiling[2]);
	floor = create_trgb(parsing->floor[0], parsing->floor[1],
			parsing->floor[2]);
	while (++x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if (y < WINDOW_HEIGHT / 2)
			{
				my_mlx_pixel_put(&mlx->img, x, y, ceil);
			}
			else if (y >= WINDOW_HEIGHT / 2)
				my_mlx_pixel_put(&mlx->img, x, y, floor);
			y++;
		}
	}
}

void	project_wall_strip(t_mlx *mlx, const t_ray *ray,
		const t_player *player, double ray_distance)
{
	double	wall_height;
	int		wall_top_pixel;

	wall_height = get_projected_wall_height(ray_distance
			* ft_cos(ray->ray.direction - player->pos.direction));
	wall_top_pixel = ((double)WINDOW_HEIGHT / 2) - (wall_height / 2);
	draw_texture_line(mlx, (t_point){ray->index, wall_top_pixel}, ray,
		wall_height);
}

void	project_3d(t_mlx *mlx, const t_player *player, t_parsing *parsing)
{
	double	ray_angle;
	t_ray	ray;
	double	dir;

	paint_ceil_ground(mlx, parsing);
	ray.ray = player->pos;
	ray.index = 0;
	ray_angle = (ray.ray.direction - (FOV / 2));
	dir = (ray.ray.direction + (FOV / 2));
	while ((ray_angle) <= (dir))
	{
		ray_angle += (double)FOV / NUM_RAYS;
		ray.ray.direction = angle_normalizer(ray_angle);
		project_wall_strip(mlx, &ray, player, get_ray_distance(&ray, parsing));
		ray.index++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
