/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:23:43 by samajat           #+#    #+#             */
/*   Updated: 2022/11/23 15:46:36 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

//Headers
#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include <stdlib.h>


//MAP
#define MAP_RAW 7
#define VECT_LEN 50
#define MAP_COL 8
#define ENTITY_SIZE 50

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
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
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


#endif