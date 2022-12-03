/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_of_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:08:20 by samajat           #+#    #+#             */
/*   Updated: 2022/12/03 19:34:39 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int point_is_vertical(const t_point *point)
{
    return (!point->Y  % ENTITY_SIZE);
}

int point_is_horizontal(const t_point *point)
{
    return (!point->X  % ENTITY_SIZE);
}
