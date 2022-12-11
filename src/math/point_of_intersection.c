/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_of_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:08:20 by samajat           #+#    #+#             */
/*   Updated: 2022/12/11 19:48:55 by samajat          ###   ########.fr       */
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



// t_point get_first_intersection_point_with_vectrics(const   t_vector    *ray)
// {
//     int x;
//     int y;

//     x = floor(ray->origPoint.X / ENTITY_SIZE) * ENTITY_SIZE;
//     y = -1 * (tan(convert_degree_to_radian(ray->direction)) * (x - ray->origPoint.X) - ray->origPoint.Y);
//     return ((t_point){x, y});
// }

// t_point get_first_intersection_point_with_horizons(const   t_vector    *ray)
// {
//     int x;
//     int y;

//     y = floor(ray->origPoint.Y / ENTITY_SIZE) * ENTITY_SIZE;
//     x = (ray->origPoint.Y - y)/ tan(3*M_PI/2) + ray->origPoint.X;
//     x = (ray->origPoint.Y - y)/ tan(convert_degree_to_radian(ray->direction)) + ray->origPoint.X;
//     return ((t_point){x, y});
// }

// t_point get_ray_last_intersection_with_vectrics(const   t_vector    *ray)
// {
//     int     x;
//     int     y;
//     int     xstep;
//     int     ystep;
//     t_point first_point;

//     first_point = get_first_intersection_point_with_vectrics(ray);
//     printf("vertical first intersection is : (x=%d, y=%d)\n", first_point.X, first_point.Y);
//     x = first_point.X;
//     y = first_point.Y;
//     xstep = ENTITY_SIZE;
//     ystep = xstep * tan(convert_degree_to_radian(ray->direction));
//     while (point_is_not_a_wall((t_point){x, y}))
//     {
//         x += xstep;
//         y += ystep;
//     }
//     return ((t_point){x, y});
// }

// t_point get_ray_last_intersection_with_horizons(const   t_vector    *ray)
// {
//     int     x;
//     int     y;
//     double     xstep;
//     double     ystep;
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

// t_point get_ray_distance(t_vector   ray, double angle)
// {
//     // t_point HoriPoint;
//     t_point VerticPoint;
//     // double  vertical_distance;
//     // double  horizontal_distance;

//     ray.direction = angle;
//     // HoriPoint = get_ray_last_intersection_with_horizons(&ray);
//     VerticPoint = get_first_intersection_point_with_vectrics(&ray);
//     VerticPoint = get_ray_last_intersection_with_vectrics(&ray);
//     // VerticPoint = get_ray_last_intersection_with_horizons(&ray);
//     // printf("Horizonatal x: %d, y:%d\n", HoriPoint.X, HoriPoint.Y);
//     // printf("Vertical x: %d, y:%d\n", VerticPoint.X, VerticPoint.Y);
//     // horizontal_distance = get_distance_of_2_point(ray.origPoint, HoriPoint);
//     // vertical_distance = get_distance_of_2_point(ray.origPoint, VerticPoint);
//     // if (horizontal_distance < vertical_distance)
//     //     return (horizontal_distance);
//     // HoriPoint.X = 100;
//     // HoriPoint.Y = 100;
//     return (VerticPoint);
// }


void    func( int *y, double *a, double *b, double angle)
{
    if (angle <= 0  && angle >= -180)
    {
        *a *= -1;
        *b *= -1;
        
        (*y)--;
    }
}
void    func1(int *x, double *a, double *b, double angle)
{
    if (!(angle <= 90  && angle >= -90))
    {
        *a *= -1;
        *b *= -1;
        
        (*x)--;
    }
}

//---------
t_point get_first_intersection_point_with_vectrics(const   t_vector    *ray)
{
    int x;
    int y;

    x = floor(ray->origPoint.X / ENTITY_SIZE) * ENTITY_SIZE;
    y = -(tan(convert_degree_to_radian(ray->direction)) * (x - ray->origPoint.X) - ray->origPoint.Y);
    return ((t_point){x, y});
}


t_point get_ray_last_intersection_with_vectrics(const   t_vector    *ray)
{
    int     x;
    int     y;
    double     xstep;
    double     ystep;
    t_point first_point;

    first_point = get_first_intersection_point_with_vectrics(ray);
    printf("vertical first intersection is : (x=%d, y=%d)\n", first_point.X, first_point.Y);
    x = first_point.X ;
    y = first_point.Y;
    xstep = ENTITY_SIZE;
    ystep = xstep * tan((convert_degree_to_radian(ray->direction)));
    func1(&x, &xstep, &ystep, ray->direction);
    while (point_is_not_a_wall((t_point){x, y}))
    {
        x += xstep;
        y += ystep;
    }
    return ((t_point){x, y});
}

t_point get_first_intersection_point_with_horizons(const   t_vector    *ray)
{
    int x;
    int y;

    y = floor(ray->origPoint.Y / ENTITY_SIZE) * ENTITY_SIZE;
    x = ray->origPoint.X + (ray->origPoint.Y - y)/ tan(convert_degree_to_radian(ray->direction)) ;
    return ((t_point){x, y});
}

t_point get_ray_last_intersection_with_horizons(const   t_vector    *ray)
{
    int     x;
    int     y;
    double     xstep;
    double     ystep;
    t_point first_point;

    first_point = get_first_intersection_point_with_horizons(ray);
    printf("float -->%f\n", ray->direction);
    printf("horizon first intersection is : (x=%d, y=%d)\n", first_point.X, first_point.Y - 1);
    x = first_point.X;
    y = first_point.Y;
    ystep = ENTITY_SIZE;
    xstep = ystep/tan(convert_degree_to_radian(ray->direction));
    func(&y, &xstep, &ystep, ray->direction);
    while (point_is_not_a_wall((t_point){x, y}))
    {
        x += (xstep);
        y += (ystep);
    }
    return ((t_point){x, y});
}

t_point get_ray_distance(t_vector   ray, double angle)
{
    t_point HoriPoint;
    t_point VerticPoint;
    double  vertical_distance;
    double  horizontal_distance;

    (void)angle;
    ray.direction = -90;
    HoriPoint = get_first_intersection_point_with_horizons(&ray);
    HoriPoint = get_ray_last_intersection_with_horizons(&ray);
    // VerticPoint = get_first_intersection_point_with_vectrics(&ray);
    VerticPoint = get_ray_last_intersection_with_vectrics(&ray);
    printf("Horizonatal x: %d, y:%d, Direction:%f\n", HoriPoint.X, HoriPoint.Y, ray.direction);
    printf("Vertical x: %d, y:%d\n", VerticPoint.X, VerticPoint.Y);
    horizontal_distance = get_distance_of_2_point(ray.origPoint, HoriPoint);
    vertical_distance = get_distance_of_2_point(ray.origPoint, VerticPoint);
    if (horizontal_distance < vertical_distance)
        return (HoriPoint);
    // HoriPoint.X = 100;
    // HoriPoint.Y = 100;
    return (VerticPoint);
    // return (HoriPoint);
}