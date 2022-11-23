/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:16:48 by samajat           #+#    #+#             */
/*   Updated: 2022/11/23 21:49:44 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void rotate(t_mlx *mlx, t_vector *vector , float angle)
{
    
    angle = convert_degree_to_radian(angle);
    draw_line(mlx, vector->dirPoint, (t_point){vector->dirPoint.X + cos(angle) * vector->magnitude,\
        vector->dirPoint.Y + sin(angle) * vector->magnitude});
}



void    draw_vector(t_mlx *mlx, t_vector *vector)
{
    draw_line(mlx, vector->origPoint, vector->dirPoint);
}

void    render_player(t_mlx *mlx)
{
    
}
