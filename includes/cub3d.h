/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:23:43 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 19:36:04 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//Headers
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//MAP
# define TILE_SIZE 64

# define WINDOW_WIDTH 720
# define WINDOW_HEIGHT 720

//FOV (Field of vision)
# define FOV 60

# define TO_LEFT -1
# define TO_RIGHT 1
# define RAY_LENGTH 10
# define NUM_RAYS WINDOW_WIDTH

//Player speed
# define PLAYER_SPEED 10

# define BUFFER_SIZE 10000

//Keys
enum			e_KEYS
{
	MOVE_LEFT_KEY = 0,
	MOVE_RIGHT_KEY = 2,
	MOVE_FRONT_KEY = 13,
	MOVE_BACK_KEY = 1,
	TURN_LEFT_KEY = 123,
	TURN_RIGHT_KEY = 124,
	ESC = 53,
};

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;
	char		*path;
}				t_img;

//Texture
typedef struct s_texture
{
	t_img		north;
	t_img		east;
	t_img		west;
	t_img		south;
}				t_texture;

//Data structures
typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_texture	texture;
}				t_mlx;

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct s_vector
{
	t_point		orig_point;
	double		direction;
}				t_vector;

typedef struct s_player
{
	t_vector	pos;
	void		*img;
}				t_player;

typedef struct s_ray
{
	t_vector	ray;
	int			index;
	bool		is_right;
	bool		is_up;
	bool		intersect_is_vertical;
	t_point		intersect_point;
}				t_ray;

typedef struct s_buttons
{
	int			da_button;
	int			ws_button;
	int			rotate_button;
}				t_buttons;

typedef struct s_parsing
{
	char		**map;
	int			ceiling[3];
	int			floor[3];
	int			max_line;
	int			num_lines;
	int			empty_lines;
	t_vector	default_player_data;
	char		*so_path;
	char		*no_path;
	char		*we_path;
	char		*ea_path;
}				t_parsing;

typedef struct s_param
{
	t_mlx		*mlx;
	t_player	*player;
	t_parsing	*parsing;
	t_buttons	buttons;
}				t_param;

//Temp
int				printPlayerData(t_player *parm);

//Rendering functions
void			render_map_grid(t_mlx *mlx);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

//Math funcs
double			degree2rad(double dgreeValue);
double			get_distance_of_2_point(t_point a, t_point b);
double			angle_normalizer(double angle);
double			get_projected_wall_height(double ray_distance_from_wall);
double			ft_cos(double angle_degree);
double			ft_sin(double angle_degree);
double			ft_tan(double angle_degree);

//Moves Listener
void			move_left(t_player *player, t_parsing *parsing);
void			moveRight(t_player *player, t_parsing *parsing);
void			moveFront(t_player *player, t_parsing *parsing);
void			moveBack(t_player *player, t_parsing *parsing);
int				point_is_not_a_wall(t_point dstPoint, const t_parsing *parsing);

//Rotation Listener
void			turn_right(t_player *player);
void			turn_left(t_player *player);
void			turnUp(t_player *player);
void			turnDown(t_player *player);
void			rotate_player(t_player *player, int dir, double angleToRotate);
void			render_map_player(t_mlx *mlx, t_player *player);

//main events func
void			event_perceiver(t_mlx *mlx, t_player *player,
					t_parsing *parsing);
void			update_ws_buttons(t_param	*param);
void			update_ad_buttons(t_param	*param);
int				mouse_move(int x, int y, t_param *param);
int				press_key(int keyCode, t_param *param);
int				release(int keyCode, t_param *param);
int				render(t_param *parm);

//set to default
void			set_player_default_info(t_player *player, t_parsing *parsing);
void			set_buttons_2_default(t_buttons *buttons);

//image
void			draw_rectangle(t_mlx *mlx, t_point point, int COLOR);
t_img			ft_creat_an_image(t_mlx *mlx);
int				create_trgb(int r, int g, int b);

//point_of_intersection
int				point_is_vertical(int y);
int				point_is_horizontal(int x);
double			get_ray_distance(t_ray *ray, t_parsing *parsing);

//Ray
void			set_ray_to_default(t_ray *ray);
void			set_ray_direction(t_ray *ray);
void			set_ray_intercetions(t_ray *ray, t_point coords);

//2d
void			D2d_map(t_mlx *mlx, t_player *player);
void			draw_texture_strip(t_mlx *mlx, const t_ray *ray,
					const t_player *player, double ray_distance);

//3d
void			draw_texture_line(t_mlx *mlx, t_point point, const t_ray *ray,
					double height);
void			project_3d(t_mlx *mlx, const t_player *player,
					t_parsing *parsing);
void			project_wall_strip(t_mlx *mlx, const t_ray *ray,
					const t_player *player, double ray_distance);

//Texture
int				get_texture_x(const t_ray *ray);
void			*set_up_texture(t_mlx *mlx, t_parsing *parsing);
void			init_texture(t_mlx	*mlx);
void			*set_no_eas_text(t_mlx *mlx, t_parsing *parsing);
void			*set_we_so_text(t_mlx *mlx, t_parsing *parsing);

// extract_line
void			extract_line(char **content, t_parsing *parsing);
void			check_color_line(char *line, t_parsing *parsing);
void			check_each_line(char *line, char *direction,
					t_parsing *parsing);
void			check_line(char *line, t_parsing *parsing);
int				lines_before_map(char *content);
// fill_parsing
void			fill_map_with_z(t_parsing *parsing);
void			fill_color(char line, char *sub, t_parsing *parsing, int k);
void			fill_direction(t_parsing *parsing, int k, int s);
void			condition_texture(t_parsing *parsing, char direction,
					char *line);
// layers
int				layeronechecker(char *line);
int				layertwochecker(char *line);
int				layerthreechecker(char *line, t_parsing *parsing);
int				ft_parser(int ac, char **av, t_parsing *parsing);
// map_handling
void			check_map_error(t_parsing *parsing);
int				check_up_down(t_parsing *parsing, int i, int j);
void			malloc_map(t_parsing *parsing, char **content, int i);
void			tallest_line(char **content, int i, t_parsing *parsing);
void			condition(char **content, int i, t_parsing *parsing);
// utils
int				is_space(char line);
int				color_is_valid(char *color);
int				num_of_comma(char *line);
void			free_dub(char **s);
int				check_argument_error(int ac, char **av);
char			**read_map(char *av);
int				dubstrlen(char **content);

// init_parsing
void			init_parsing(t_parsing *parsing);
// get_next_line
char			*get_next_line(int fd);

//utils
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
int				ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_isdigit(int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			**ft_split(char const *s, char c);
char			*ft_strjoin_read(char *s1, char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_free_data(t_parsing *parsing, t_param *param);
void			set_parsing_2_null(t_parsing *parsing);

//exit
int				exit_game_t(t_parsing *parsing, t_mlx *mlx);
void			ft_exit(t_parsing *parsing, t_param *param);
int				exit_game(t_param *param);
#endif