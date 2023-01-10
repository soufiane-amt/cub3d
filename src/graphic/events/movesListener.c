/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesListener.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:04 by samajat           #+#    #+#             */
/*   Updated: 2023/01/06 15:19:52 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	within_wall(int x, int y, const t_parsing *parsing)
{
	(void)parsing;
	return ((x >= 0 && x < parsing->max_line) && (y >= 0
			&& y < parsing->num_lines));
}

int	point_is_not_a_wall(t_point dst_point, const t_parsing *parsing)
{
	int	x;
	int	y;

	x = (dst_point.x / TILE_SIZE);
	y = (dst_point.y / TILE_SIZE);
	if (!within_wall(x, y, parsing))
		return (0);
	if (parsing->map[y][x] == '1')
		return (0);
	return (1);
}

int	mouse_move(int x, int y, t_param *param)
{
	static int	last = -1;

	if (y > WINDOW_HEIGHT || y < 0 || x > WINDOW_WIDTH || x < 0)
		return (0);
	if (x < last)
	{
		rotate_player(param->player, TO_LEFT, 3);
		last = x;
	}
	else if (x > last)
	{
		rotate_player(param->player, TO_RIGHT, 3);
		last = x;
	}
	return (0);
}
