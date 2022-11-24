/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:16:48 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 20:31:53 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void    put_ground_to_default()
// {
    
// }

void rotatePlayer (t_player *player , int dir, float angleToRotate)
{
    player->pos.direction = player->pos.direction + (dir * angleToRotate);
}

void launch_ray(t_mlx *mlx, const t_vector *vector , float angleToRotate)
{
    angleToRotate = convert_degree_to_radian(vector->direction + angleToRotate);
    
    draw_line(mlx, vector->origPoint, (t_point){vector->origPoint.X + cos(angleToRotate) * vector->magnitude,\
        vector->origPoint.Y + sin(angleToRotate) * vector->magnitude});
}


// void    draw_vector(t_mlx *mlx, t_vector *vector)
// {
//     draw_line(mlx, vector->origPoint, vector->dirPoint);
// }

