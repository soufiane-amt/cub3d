/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_of_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:08:20 by samajat           #+#    #+#             */
/*   Updated: 2022/12/03 21:19:12 by samajat          ###   ########.fr       */
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

int get_ray_last_intersection_with_vectrics(const   t_vector    *ray)
{
    
}

int get_ray_last_intersection_with_horizons(const   t_vector    *ray)
{
    
}

// int get_ray_distance(const t_vector   *ray)
// {
        
// }