/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:30:12 by samajat           #+#    #+#             */
/*   Updated: 2022/11/25 21:41:39 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void launch_ray(t_mlx *mlx, const t_vector *vector , float angleToRotate)
{
    angleToRotate = convert_degree_to_radian(vector->direction + angleToRotate);
    
    draw_line(mlx, vector->origPoint, (t_point){vector->origPoint.X + cos(angleToRotate) * vector->magnitude,\
        vector->origPoint.Y + sin(angleToRotate) * vector->magnitude});
}


void    fire_rays(t_mlx *mlx,  t_vector *vector)
{
    int i;

    i = vector->direction - FOV/2;
    while (i <= vector->direction + FOV/2)
    {
        launch_ray(mlx, vector, i);
        i++;
    }    
}