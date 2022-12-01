/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:54:10 by samajat           #+#    #+#             */
/*   Updated: 2022/12/01 11:05:54 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*( int *)pixel = color;
}

//temp
void draw_rectangle(t_mlx *mlx, t_point point, int COLOR)
{
    int i;
    int j;

    i = 0;
    while (i < ENTITY_SIZE)
    {
        j = 0;
        while (j < ENTITY_SIZE)
        {
            my_mlx_pixel_put(&mlx->img, point.X + i, point.Y + j, COLOR);
            j++;
        }
        i++;
    }
}

t_img   ft_creat_an_image(t_mlx *mlx)
{
    t_img   image;
    image.img = mlx_new_image(mlx->mlx, WINDOW_SIZEX, WINDOW_SIZEY);
    image.addr = mlx_get_data_addr(image.img, &image.bpp,
        &image.line_len, &image.endian);
    return (image);
}