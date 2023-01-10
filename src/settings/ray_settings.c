/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:42:06 by samajat           #+#    #+#             */
/*   Updated: 2023/01/03 17:19:34 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_to_default(t_ray *ray)
{
	ray->is_right = false;
	ray->is_up = false;
	ray->intersect_is_vertical = false;
}

void	set_ray_direction(t_ray *ray)
{
	set_ray_to_default(ray);
	if (ray->ray.direction < 360 && ray->ray.direction > 180)
		ray->is_up = true;
	if (ray->ray.direction > 270 || ray->ray.direction < 90)
		ray->is_right = true;
}

void	set_ray_intercetions(t_ray *ray, t_point coords)
{
	ray->ray.orig_point = coords;
}
