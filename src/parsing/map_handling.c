/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:52:35 by akadi             #+#    #+#             */
/*   Updated: 2023/01/03 19:08:26 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_error(t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	while (parsing->map[i])
	{
		j = 0;
		while (parsing->map[i][j])
		{
			if (i + 1 == parsing->num_lines
				&& !lines_before_map(parsing->map[i]))
			{
				perror("Error\n Map error");
				exit(1);
			}
			if (parsing->map[i][j] == '0' && !check_up_down(parsing, i, j))
			{
				perror("Error\n Map error");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	check_up_down(t_parsing *parsing, int i, int j)
{
	if (parsing->map[i - 1][j] == '*' || parsing->map[i + 1][j] == '*')
		return (0);
	if (parsing->map[i][j - 1] == '*' || parsing->map[i][j + 1] == '*')
		return (0);
	else
		return (1);
}

void	malloc_map(t_parsing *parsing, char **content, int i)
{
	int		k;
	int		z;
	char	*trim;

	k = -1;
	parsing->num_lines = parsing->num_lines - i;
	parsing->map = malloc(sizeof(char *) * parsing->num_lines + 1);
	while (++k < parsing->num_lines)
		parsing->map[k] = malloc(sizeof(char) * parsing->max_line + 1);
	k = -1;
	while (++k < parsing->num_lines)
	{
		trim = ft_strtrim(content[i], "\n");
		z = ft_strlcpy(parsing->map[k], trim, parsing->max_line + 1);
		while (z < parsing->max_line)
		{
			parsing->map[k][z] = '*';
			if (z + 1 == parsing->max_line)
				parsing->map[k][z + 1] = '\0';
			z++;
		}
		i++;
		free(trim);
	}
	parsing->map[k] = NULL;
}

void	tallest_line(char **content, int i, t_parsing *parsing)
{
	int		len;
	char	*trim;

	while (content[i])
	{
		trim = ft_strtrim(content[i], "\n");
		len = ft_strlen(trim);
		if (parsing->max_line < len)
			parsing->max_line = len;
		i++;
		free(trim);
	}
}

void	condition(char **content, int i, t_parsing *parsing)
{
	if (i - parsing->empty_lines - 1 < 5)
	{
		perror("Error\n Missing data");
		exit(1);
	}
	else
	{
		tallest_line(content, i, parsing);
		malloc_map(parsing, content, i);
		fill_map_with_z(parsing);
		check_map_error(parsing);
		if (parsing->default_player_data.direction == -1)
		{
			perror("Error\n no direction");
			exit(1);
		}
	}
}
