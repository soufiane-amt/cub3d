/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:49:20 by akadi             #+#    #+#             */
/*   Updated: 2023/01/03 19:09:00 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	layeronechecker(char *line)
{
	if (num_of_comma(line) == 2 && (line[0] == 'F' || line[0] == 'C')
		&& (line[1] == ' ' || line[1] == '\t'))
		return (1);
	return (0);
}

int	layertwochecker(char *line)
{
	int	i;

	i = 2;
	while (line[i] && is_space(line[i]))
		i++;
	while (line[i])
	{
		if (!is_space(line[i]) && !ft_isdigit(line[i]) && line[i] != ',')
			return (0);
		i++;
	}
	return (1);
}

int	layerthreechecker(char *line, t_parsing *parsing)
{
	int			j;
	int			i;
	static int	k;

	j = 0;
	i = 2;
	k = 0;
	while (line[i] && is_space(line[i]))
		i++;
	j = i;
	while (i <= (int)ft_strlen(line))
	{
		if (line[i] == ',' || !line[i + 1])
		{
			if (!line[i + 1])
				i++;
			if (!color_is_valid(ft_substr(line, j, i - j)))
				return (0);
			else
				fill_color(line[0], ft_substr(line, j, i - j), parsing, k++);
			j = i + 1;
		}
		i++;
	}
	return (1);
}

int	ft_parser(int ac, char **av, t_parsing *parsing)
{
	char	**content;

	if (check_argument_error(ac, av) == -1)
		return (perror("Error\n Invalid argument"), -1);
	set_parsing_2_null(parsing);
	content = read_map(av[1]);
	if (!content)
		return (perror("Error\n Invalid argument"), -1);
	parsing->num_lines = dubstrlen(content);
	extract_line(content, parsing);
	free_dub(content);
	return (0);
}
