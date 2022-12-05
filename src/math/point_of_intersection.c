/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_of_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:08:20 by samajat           #+#    #+#             */
/*   Updated: 2022/12/05 20:00:43 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int point_is_vertical(int   y)
{
    return (!(y % ENTITY_SIZE));
}

int point_is_horizontal(int x)
{
    return (!(x % ENTITY_SIZE));
}


t_point get_first_intersection_point_with_vectrics(const   t_vector    *ray)
{
    int x;
    int y;

    x = floor(ray->origPoint.X / ENTITY_SIZE) * ENTITY_SIZE;
    y = (-tan(convert_degree_to_radian(ray->direction)) * (x - ray->origPoint.X) - ray->origPoint.Y);
    return ((t_point){x, y});
}

// t_point get_first_intersection_point_with_horizons(const   t_vector    *ray)
// {
//     int x;
//     int y;

//     y = floor(ray->origPoint.Y / ENTITY_SIZE) * ENTITY_SIZE;
//     x = (ray->origPoint.Y - y)/ tan(convert_degree_to_radian(ray->direction)) + ray->origPoint.X;
//     return ((t_point){x, y});
// }

t_point get_ray_last_intersection_with_vectrics(const   t_vector    *ray)
{
    int     x;
    int     y;
    int     xstep;
    int     ystep;
    t_point first_point;

    first_point = get_first_intersection_point_with_vectrics(ray);
    printf("vertical first intersection is : (x=%d, y=%d)\n", first_point.X, first_point.Y);
    x = first_point.X;
    y = first_point.Y;
    xstep = ENTITY_SIZE;
    ystep = xstep * tan(convert_degree_to_radian(ray->direction));
    printf("=====>direction:%f, angle:%f\n", tan(convert_degree_to_radian(ray->direction)), ray->direction);
    while (point_is_not_a_wall((t_point){x, y}))
    {
        x += xstep;
        y += ystep;
    }
    return ((t_point){x, y});
}

// t_point get_ray_last_intersection_with_horizons(const   t_vector    *ray)
// {
//     int     x;
//     int     y;
//     int     xstep;
//     int     ystep;
//     t_point first_point;

//     first_point = get_first_intersection_point_with_horizons(ray);
//     printf("horizon first intersection is : (x=%d, y=%d)\n", first_point.X, first_point.Y);
//     x = first_point.X;
//     y = first_point.Y;
//     ystep = ENTITY_SIZE;
//     xstep = ystep/tan(convert_degree_to_radian(ray->direction));
//     while (!point_is_not_a_wall((t_point){x, y}))
//     {
//         x += xstep;
//         y += ystep;
//     }
//     return ((t_point){x, y});
// }

t_point get_ray_distance(t_vector   ray, double angle)
{
    // t_point HoriPoint;
    t_point VerticPoint;
    // double  vertical_distance;
    // double  horizontal_distance;

    (void)angle;
    // printf("(tang = %f)\n", tan(90));
    // ray.direction =  M_PI_2/2 ;
    // HoriPoint = get_ray_last_intersection_with_horizons(&ray);
    ray.direction++;
    VerticPoint = get_ray_last_intersection_with_vectrics(&ray);
    printf("X = %d\nY= %d\n", VerticPoint.X, VerticPoint.Y);
    printf("Direction: %f\n", ray.direction);
    // printf("Horizonatal x: %d, y:%d\n", HoriPoint.X, HoriPoint.Y);
    // printf("Vertical x: %d, y:%d\n", VerticPoint.X, VerticPoint.Y);
    // horizontal_distance = get_distance_of_2_point(ray.origPoint, HoriPoint);
    // vertical_distance = get_distance_of_2_point(ray.origPoint, VerticPoint);
    // if (horizontal_distance < vertical_distance)
    //     return (HoriPoint);
    return (VerticPoint);
    // return (HoriPoint);
}