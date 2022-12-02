/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:30:12 by samajat           #+#    #+#             */
/*   Updated: 2022/12/02 13:24:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void draw_line(t_mlx *mlx, const t_point point1, const t_point point2)
{
    float dx = point2.X - point1.X;
    float dy = point2.Y - point1.Y;
 
    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
 
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    float X = point1.X;
    float Y = point1.Y;
    int i = 0;
    while ( i <= steps)
    {
        if (!move_is_valid((t_point){X, Y}))
            break;
        my_mlx_pixel_put(&mlx->img, X, Y, RED);
        X += Xinc;
        Y += Yinc;
        i++;
    }
}

void launch_ray(t_mlx *mlx, const t_vector *vector , float angleToRotate)
{
    angleToRotate = convert_degree_to_radian(vector->direction + angleToRotate);
    
    draw_line(mlx, vector->origPoint, (t_point){vector->origPoint.X + cos(angleToRotate) * vector->magnitude,\
        vector->origPoint.Y + sin(angleToRotate) * vector->magnitude});
}


void    fire_rays(t_mlx *mlx,  t_vector *vector)
{
    float i;

    i = -FOV/2;
    while (i <= FOV/2)
    {
        launch_ray(mlx, vector, i);
        i += 1.0f;
    }
}