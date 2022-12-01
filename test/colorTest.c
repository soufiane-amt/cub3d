/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorTest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:42:17 by samajat           #+#    #+#             */
/*   Updated: 2022/11/30 17:21:55 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
    t_img   img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len,
								&img.endian);
    img_pix_put(&img, 500, 500, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  
	mlx_loop(mlx);
	return (0);
}
