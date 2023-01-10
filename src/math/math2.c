/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:31:25 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 15:22:13 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_cos(double angle_degree)
{
	return (cos(degree2rad(angle_degree)));
}

double	ft_sin(double angle_degree)
{
	return (sin(degree2rad(angle_degree)));
}

double	ft_tan(double angle_degree)
{
	return (tan(degree2rad(angle_degree)));
}
