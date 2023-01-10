/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:57:02 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/12/28 22:32:01 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_map(char *av)
{
	char	**content;
	char	*buffer;
	char	*save;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (NULL);
	save = ft_strdup("");
	buffer = get_next_line(fd);
	while (buffer)
	{
		save = ft_strjoin_read(save, buffer);
		buffer = get_next_line(fd);
	}
	content = ft_split(save, '\n');
	free(save);
	close(fd);
	return (content);
}

int	check_argument_error(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		return (-1);
	return (0);
}

int	dubstrlen(char **content)
{
	int	i;

	i = 0;
	while (content[i] != NULL)
		i++;
	return (i);
}

char	*ft_strjoin_read(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (free(s1), free(s2), p);
}
