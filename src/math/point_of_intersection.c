/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_of_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:08:20 by samajat           #+#    #+#             */
/*   Updated: 2022/12/03 22:22:48 by samajat          ###   ########.fr       */
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
    y = tan(convert_degree_to_radian(ray->direction)) * (x - ray->origPoint.X) - ray->origPoint.Y;
    return ((t_point){x, y});
}

t_point get_first_intersection_point_with_horizons(const   t_vector    *ray)
{
    int x;
    int y;

    y = floor(ray->origPoint.Y / ENTITY_SIZE) * ENTITY_SIZE;
    x = (ray->origPoint.Y - y)/ tan(convert_degree_to_radian(ray->direction)) + ray->origPoint.X;
    return ((t_point){x, y});
}

t_point get_ray_last_intersection_with_vectrics(const   t_vector    *ray)
{
    int     x;
    int     y;
    int     xstep;
    int     ystep;
    t_point first_point;

    first_point = get_first_intersection_point_with_vectrics(ray);
    x = first_point.X;
    y = first_point.Y;
    xstep = ENTITY_SIZE;
    ystep = xstep * tan(convert_degree_to_radian(ray->direction));
    while (!point_is_not_a_wall((t_point){x, y}))
    {
        x += xstep;
        y += ystep;
    }
    return ((t_point){x, y});
}

t_point get_ray_last_intersection_with_horizons(const   t_vector    *ray)
{
    int     x;
    int     y;
    int     xstep;
    int     ystep;
    t_point first_point;

    first_point = get_first_intersection_point_with_horizons(ray);
    x = first_point.X;
    y = first_point.Y;
    ystep = ENTITY_SIZE;
    xstep = ystep/tan(convert_degree_to_radian(ray->direction));
    while (!point_is_not_a_wall((t_point){x, y}))
    {
        x += xstep;
        y += ystep;
    }
    return ((t_point){x, y});
    
}

// int get_ray_distance(const t_vector   *ray)
// {
        // return (steps);
// }