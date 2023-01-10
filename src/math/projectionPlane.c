/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectionPlane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:13:29 by samajat           #+#    #+#             */
/*   Updated: 2023/01/05 20:02:08 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

double	get_player_distance_2_projection_plane(void)
{
	return ((WINDOW_WIDTH / 2) / ft_tan(FOV / 2));
}

double	get_projected_wall_height(double ray_distance_from_wall)
{
	return (TILE_SIZE * get_player_distance_2_projection_plane()
		/ ray_distance_from_wall);
}
