/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:08:31 by samajat           #+#    #+#             */
/*   Updated: 2022/12/19 19:03:14 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double  get_distance_of_2_point(t_point a, t_point  b)
{   
    return (sqrt( pow((b.X - a.X), 2)  +   pow((b.Y - a.Y), 2)));
}

double convert_degree_to_radian(double dgreeValue)
{
    return (dgreeValue * (M_PI/180.0));
}

double angleNormalizer(double angle)
{
    angle = remainder(angle , (360));
    if (angle < 0)
        angle = 360 + angle;
    return (angle);
}