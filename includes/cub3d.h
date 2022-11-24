/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:23:43 by samajat           #+#    #+#             */
/*   Updated: 2022/11/24 15:47:46 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

//Headers
#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include <stdlib.h>



//Window
#define WINDOW_SIZEX 1000
#define WINDOW_SIZEY 1000

//MAP
#define MAP_RAW 7
#define VECT_LEN 50
#define MAP_COL 8
#define ENTITY_SIZE 50

//FOV
#define FOV 60

//COLORS
#define RED   0xff00000
#define BLUE  255
#define GREEN 0x0000FF00
#define BLACK 0x000




//Keys
enum {
	MOVE_LEFT_KEY = 0,
	MOVE_RIGHT_KEY = 2,
	MOVE_FRONT_KEY = 13,
	MOVE_BACK_KEY = 1,
	TURN_LEFT_KEY = 123,
	TURN_RIGHT_KEY = 124,
	TURN_UP_KEY = 126,
	TURN_DOWN_KEY = 125,
};


//Data structures
typedef struct s_mlx
{
    void    *mlx;
    void    *win;
}   t_mlx;


typedef struct s_point
{
    float   X;
    float   Y;
}   t_point;

typedef struct s_vector
{
    t_point         origPoint;
    float           direction;
    const int       magnitude;
}   t_vector;


typedef struct s_player
{
    t_vector    pos;

}   t_player;



//Pixel manipulation funcs
void    draw_line(t_mlx *mlx,  t_point point1,  t_point point2);
void    launch_ray(t_mlx *mlx, const t_vector *vector , float angleToRotate);

//Rendering functions
void    render_grid(t_mlx *mlx);


//Math funcs
float convert_degree_to_radian(float dgreeValue);

#endif