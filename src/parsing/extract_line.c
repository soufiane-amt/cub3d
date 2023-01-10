/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:46:12 by akadi             #+#    #+#             */
/*   Updated: 2023/01/03 19:08:26 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_color_line(char *line, t_parsing *parsing)
{
	if (layeronechecker(line) && layertwochecker(line)
		&& layerthreechecker(line, parsing))
		return ;
	else
	{
		perror("Error\n Misconfigured color");
		exit(1);
	}
}

void	check_each_line(char *line, char *direction, t_parsing *parsing)
{
	int	i;
	int	fd;

	i = -1;
	if ((!ft_strncmp(line, direction, 3) || !ft_strncmp(&line[2], "\t", 1))
		&& ft_strnstr(line, "./src/texture/texture_img/", ft_strlen(line)))
	{
		line = ft_strnstr(line, "./src/texture/texture_img/", ft_strlen(line));
		fd = open(line, O_RDONLY);
		if (fd < 0 || (ft_strcmp(line, "./src/texture/texture_img/blue.xpm")
				&& ft_strcmp(line, "./src/texture/texture_img/redBrick.xpm")
				&& ft_strcmp(line, "./src/texture/texture_img/eagle.xpm")
				&& ft_strcmp(line, "./src/texture/texture_img/khilota.xpm")))
		{
			perror("Error\n Texture file error");
			exit(1);
		}
		close(fd);
		condition_texture(parsing, direction[0], line);
	}
	else
	{
		perror("ERROR\n Texture file error");
		exit(1);
	}
}

void	check_line(char *line, t_parsing *parsing)
{
	if (line[0] && line[0] == 'N')
		check_each_line(line, "NO ", parsing);
	else if (line[0] && line[0] == 'S')
		check_each_line(line, "SO ", parsing);
	else if (line[0] && line[0] == 'W')
		check_each_line(line, "WE ", parsing);
	else if (line[0] && line[0] == 'E')
		check_each_line(line, "EA ", parsing);
	else if (line[0] && line[0] == 'F')
		check_color_line(line, parsing);
	else if (line[0] && line[0] == 'C')
		check_color_line(line, parsing);
	else if (line[0])
	{
		perror("Error\nMap Error");
		exit(1);
	}
	else
		parsing->empty_lines += 1;
}

int	lines_before_map(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != '1' && content[i] != ' ' && content[i] != '\t'
			&& content[i] != '*')
			return (0);
		i++;
	}
	return (1);
}

void	extract_line(char **content, t_parsing *parsing)
{
	int		i;
	char	*line;

	i = -1;
	while (content[++i])
	{
		line = ft_strtrim(content[i], "\t \n");
		if (line[0] && lines_before_map(line))
		{
			free(line);
			break ;
		}
		check_line(line, parsing);
		free(line);
	}
	condition(content, i, parsing);
}
