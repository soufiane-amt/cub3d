/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:23:43 by samajat           #+#    #+#             */
/*   Updated: 2022/11/23 16:56:53 by samajat          ###   ########.fr       */
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

//
#define FOV 60

char map[MAP_COL][MAP_RAW] = {{'1', '1', '1', '1', '1', '1', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '1', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', 'N', '0', '1'},
                {'1', '1', '1', '1', '1', '1', '1'}};


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
    float   x;
    float   y;
}   t_point;

typedef struct s_vector
{
    t_point   origPoint;
    t_point   dirPoint;
    float     angle;
}   t_vector;


typedef struct s_player
{
    t_vector    pos;

}   t_player;


#endif