/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_of_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:08:20 by samajat           #+#    #+#             */
/*   Updated: 2023/01/05 18:57:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	get_first_intersection_point_with_vectrics(t_ray *ray)
{
	double	x_steps;
	double	y_steps;
	int		adjuster;

	adjuster = 0;
	if (ray->is_right)
		adjuster = TILE_SIZE;
	x_steps = floor(ray->ray.orig_point.x / TILE_SIZE) * TILE_SIZE;
	x_steps += adjuster;
	y_steps = ray->ray.orig_point.y + (ft_tan(ray->ray.direction)
			* (x_steps - ray->ray.orig_point.x));
	if (!ray->is_right)
		x_steps -= 1;
	return ((t_point){x_steps, y_steps});
}

t_point	get_ray_last_intersection_with_vectrics(t_ray *ray, t_parsing *parsing)
{
	t_point	last_point;
	double	xstep;
	double	ystep;
	t_point	first_point;

	first_point = get_first_intersection_point_with_vectrics(ray);
	last_point = first_point;
	xstep = TILE_SIZE;
	ystep = (TILE_SIZE * ft_tan(ray->ray.direction));
	if (!ray->is_right)
		xstep *= -1;
	if (ray->is_up && ystep > 0)
		ystep *= -1;
	if (!ray->is_up && ystep < 0)
		ystep *= -1;
	while (point_is_not_a_wall(last_point, parsing))
	{
		last_point.x += xstep;
		last_point.y += ystep;
	}
	return (last_point);
}

t_point	get_first_intersection_point_with_horizons(t_ray *ray)
{
	double	x_steps;
	double	y_steps;
	int		adjuster;

	adjuster = 0;
	if (!ray->is_up)
		adjuster = TILE_SIZE;
	y_steps = floor(ray->ray.orig_point.y / TILE_SIZE) * (TILE_SIZE);
	y_steps += adjuster;
	x_steps = (ray->ray.orig_point.x + (y_steps - ray->ray.orig_point.y)
			/ ft_tan(ray->ray.direction));
	if (ray->is_up)
		y_steps -= 1;
	return ((t_point){x_steps, y_steps});
}

t_point	get_ray_last_intersection_with_horizons(t_ray *ray, t_parsing *parsing)
{
	t_point	last_point;
	double	xstep;
	double	ystep;
	t_point	first_point;

	first_point = get_first_intersection_point_with_horizons(ray);
	last_point = first_point;
	ystep = TILE_SIZE;
	xstep = (TILE_SIZE / ft_tan(ray->ray.direction));
	if (ray->is_up)
		ystep *= -1;
	if (!ray->is_right && xstep > 0)
		xstep *= -1;
	if (ray->is_right && xstep < 0)
		xstep *= -1;
	while (point_is_not_a_wall(last_point, parsing))
	{
		last_point.x += xstep;
		last_point.y += ystep;
	}
	return (last_point);
}

double	get_ray_distance(t_ray *ray, t_parsing *parsing)
{
	t_point	hori_intersect;
	t_point	vertic_intersect;
	double	vertical_distance;
	double	horizontal_distance;

	set_ray_direction(ray);
	vertic_intersect = get_ray_last_intersection_with_vectrics(ray, parsing);
	hori_intersect = get_ray_last_intersection_with_horizons(ray, parsing);
	horizontal_distance = get_distance_of_2_point(ray->ray.orig_point,
			hori_intersect);
	vertical_distance = get_distance_of_2_point(ray->ray.orig_point,
			vertic_intersect);
	if (horizontal_distance < vertical_distance)
	{
		ray->intersect_point = hori_intersect;
		return (horizontal_distance);
	}
	ray->intersect_point = vertic_intersect;
	ray->intersect_is_vertical = true;
	return (vertical_distance);
}
