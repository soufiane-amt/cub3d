/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:30:12 by samajat           #+#    #+#             */
/*   Updated: 2022/12/18 22:29:18 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void draw_line(t_mlx *mlx, const t_point point1, const t_point point2)
{
    double dx = point2.X - point1.X;
    double dy = point2.Y - point1.Y;
 
    double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    double Xinc = dx / (double)steps;
    double Yinc = dy / (double)steps;
 
    double X = point1.X;
    double Y = point1.Y;
    int i = 0;
    while ( i <= steps)
    {
        my_mlx_pixel_put(&mlx->img, X, Y, RED);
        X += Xinc;
        Y += Yinc;
        i++;
    }
}

void launch_ray(t_mlx *mlx, const t_vector *vector , double angleToRotate)
{
    angleToRotate = convert_degree_to_radian(vector->direction + angleToRotate);
    double steps = get_ray_distance(*vector, angleToRotate);
    draw_line(mlx, vector->origPoint, (t_point){(vector->origPoint.X + (cos((angleToRotate)) * steps)), 
    (vector->origPoint.Y + (sin((angleToRotate)) * steps))});
}


void    fire_rays(t_mlx *mlx,  t_vector *vector)
{
    double i;

    i = -FOV/2;
    while (i <= FOV/2)
    {
        launch_ray(mlx, vector, i);
        i += 0.01f;
    }
}