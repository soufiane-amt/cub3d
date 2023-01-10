/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:00:06 by akadi             #+#    #+#             */
/*   Updated: 2023/01/05 18:57:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map_with_z(t_parsing *parsing)
{
	int	s;
	int	k;

	k = 0;
	s = 0;
	while (parsing->map[k])
	{
		s = 0;
		while (parsing->map[k][s])
		{
			fill_direction(parsing, k, s);
			s++;
		}
		k++;
	}
}

void	fill_color(char line, char *sub, t_parsing *parsing, int k)
{
	if (line == 'C')
	{
		parsing->ceiling[k] = ft_atoi(sub);
		free(sub);
	}
	if (line == 'F')
	{
		parsing->floor[k] = ft_atoi(sub);
		free(sub);
	}
}

double	char2degree(char dir)
{
	if (dir == 'N')
		return (270);
	else if (dir == 'S')
		return (90);
	else if (dir == 'W')
		return (180);
	return (0);
}

void	fill_direction(t_parsing *pars, int k, int s)
{
	if (pars->map[k][s] == ' ' || pars->map[k][s] == '\t')
		pars->map[k][s] = '*';
	else if (pars->map[k][s] == 'E' || pars->map[k][s] == 'S'
			|| pars->map[k][s] == 'W' || pars->map[k][s] == 'N')
	{
		if (pars->default_player_data.direction == -1)
		{
			perror("Error\n Direction full");
			exit(1);
		}
		pars->default_player_data.direction = char2degree(pars->map[k][s]);
		pars->default_player_data.orig_point.x = s * TILE_SIZE
			+ TILE_SIZE / 2;
		pars->default_player_data.orig_point.y = k * TILE_SIZE
			+ TILE_SIZE / 2;
		pars->map[k][s] = '0';
	}
	else if (pars->map[k][s] != '0' && pars->map[k][s] != '1'
			&& pars->map[k][s] != '*')
	{
		perror("Error\n invalid map");
		exit(1);
	}
}

void	condition_texture(t_parsing *parsing, char direction, char *line)
{
	if (parsing->so_path == NULL && direction == 'S')
		parsing->so_path = ft_strdup(line);
	else if (parsing->no_path == NULL && direction == 'N')
		parsing->no_path = ft_strdup(line);
	else if (parsing->ea_path == NULL && direction == 'E')
		parsing->ea_path = ft_strdup(line);
	else if (parsing->we_path == NULL && direction == 'W')
		parsing->we_path = ft_strdup(line);
	else
	{
		perror("Error\n Duplicate symbol");
		exit(1);
	}
}
