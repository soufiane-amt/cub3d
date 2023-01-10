/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:08:31 by samajat           #+#    #+#             */
/*   Updated: 2023/01/04 19:31:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_distance_of_2_point(t_point a, t_point b)
{
	return (sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)));
}

double	degree2rad(double dgreeValue)
{
	return (dgreeValue * (M_PI / 180.0));
}

double	angle_normalizer(double angle)
{
	angle = remainder(angle, (360));
	if (angle < 0)
		angle = 360 + angle;
	return (angle);
}
