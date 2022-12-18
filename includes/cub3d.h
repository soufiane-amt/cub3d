/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:23:43 by samajat           #+#    #+#             */
/*   Updated: 2022/12/17 15:52:26 by samajat          ###   ########.fr       */
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
#define MAP_COL 8
// #define MAP_RAW 33
// #define MAP_COL 14
#define ENTITY_SIZE 64


//Window
#define WINDOW_SIZEX MAP_RAW * ENTITY_SIZE
#define WINDOW_SIZEY MAP_COL * ENTITY_SIZE

//FOV (Field of vision)
#define FOV 60
#define TO_LEFT   -1
#define TO_RIGHT   1
#define RAY_LENGTH WINDOW_SIZEX

//COLORS
#define RED   0xff00000
#define BLUE  255
#define GREEN 0x0000FF00
#define BLACK 0x000

extern char map[MAP_COL][MAP_RAW];

//Relative paths
#define AVATAR_IMG "./src/img/redCircle.xpm"

//Player speed
#define PLAYER_SPEED 7
//Keys
enum KEYS {
	MOVE_LEFT_KEY = 0,
	MOVE_RIGHT_KEY = 2,
	MOVE_FRONT_KEY = 13,
	MOVE_BACK_KEY = 1,
	TURN_LEFT_KEY = 123,
	TURN_RIGHT_KEY = 124,
	TURN_UP_KEY = 126,
	TURN_DOWN_KEY = 125,
};


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;


//Data structures
typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    t_img   img;
}   t_mlx;


typedef struct s_point
{
    int   X;
    int   Y;
}   t_point;


typedef struct s_vector
{
    t_point         origPoint;
    double          direction;
    double          magnitude;
}   t_vector;


typedef struct s_player
{
    t_vector    pos;
    void        *img;
}   t_player;


typedef struct s_param
{
    t_mlx       *mlx;
    t_player    *player;
}t_param;





//Temp
int    printPlayerData(t_player *parm);

//Pixel manipulation funcs
void draw_line(t_mlx *mlx, const t_point point1, const t_point point2);
void    launch_ray(t_mlx *mlx, const t_vector *vector , double angleToRotate);
void    fire_rays(t_mlx *mlx,  t_vector *vector);

//Rendering functions
void    render_grid(t_mlx *mlx);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);


//Math funcs
double  convert_degree_to_radian(double dgreeValue);
double  get_distance_of_2_point(t_point a, t_point  b);


//Moves Listener
void    moveLeft(t_player  *player);
void    moveRight(t_player  *player);
void    moveFront(t_player  *player);
void    moveBack(t_player  *player);
int     point_is_not_a_wall (t_point  dstPoint);

//Rotation Listener
void    turnRight(t_player  *player);
void    turnLeft(t_player  *player);
void    turnUp  (t_player  *player);
void    turnDown(t_player  *player);
void    rotatePlayer (t_player *player , int dir, double angleToRotate);
void    renderPlayer(t_mlx *mlx, t_player *player);

//main events func
void    eventPerceiver(t_mlx *mlx, t_player *player);

//set to default
void    set_player_default_info(t_mlx *mlx, t_player *player);

//image
void 	draw_rectangle(t_mlx *mlx, t_point point, int COLOR);
t_img	ft_creat_an_image(t_mlx *mlx);

//point_of_intersection
int		point_is_vertical  (int	y);
int	 	point_is_horizontal(int	x);
double 	get_ray_distance(t_vector   ray, double angle);

//exit
void	exit_game(t_mlx	*mlx);
#endif