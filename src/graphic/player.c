/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:16:48 by samajat           #+#    #+#             */
/*   Updated: 2022/11/23 23:24:46 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void send_ray(t_mlx *mlx, const t_vector *vector , float angleToRotate)
{
    
    angleToRotate = convert_degree_to_radian(vector->direction + angleToRotate);
    draw_line(mlx, vector->origPoint, (t_point){vector->origPoint.X + cos(angleToRotate) * vector->magnitude,\
        vector->origPoint.Y + sin(angleToRotate) * vector->magnitude});
}


// void    draw_vector(t_mlx *mlx, t_vector *vector)
// {
//     draw_line(mlx, vector->origPoint, vector->dirPoint);
// }

// void    render_player(t_mlx *mlx)
// {
    
// }
