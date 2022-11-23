/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:41:57 by samajat           #+#    #+#             */
/*   Updated: 2022/11/23 17:02:45 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    set_up_mlx(t_mlx    *mlx, char* title)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, WINDOW_SIZEX, WINDOW_SIZEY, title);
}

int main ()
{
    t_mlx   mlx;

    set_up_mlx(&mlx, "cub3d");
    
}