/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:16:48 by samajat           #+#    #+#             */
/*   Updated: 2022/11/23 19:20:54 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    draw_vector(t_mlx *mlx, t_vector *vector)
{
    draw_line(mlx, vector->origPoint, vector->dirPoint);
    
}

void    render_player(t_mlx *mlx)
{
    
}
