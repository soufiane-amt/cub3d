/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:08:31 by samajat           #+#    #+#             */
/*   Updated: 2022/12/15 18:17:47 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double  get_distance_of_2_point(t_point a, t_point  b)
{
    return (sqrt( pow((b.X - a.X), 2)  +    pow((b.Y - a.Y), 2)));
    // double dx = b.X - a.X;
    // double dy = b.Y - a.Y;
 
    // return (fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy));
}

double convert_degree_to_radian(double dgreeValue)
{
    return (dgreeValue * (M_PI/180.0));
}