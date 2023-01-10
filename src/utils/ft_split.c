/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:06:44 by akadi             #+#    #+#             */
/*   Updated: 2022/12/28 22:48:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_countw(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != c)
		j++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

int	ft_lencount(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

void	ft_free(char **ml)
{
	int	i;

	i = 0;
	while (ml[i])
	{
		free(ml[i]);
		i++;
	}
	free(ml);
}

char	**split2(char **ml, const char *s, char c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s[++i] && j < ft_countw(s, c))
	{
		if (s[i] != c)
		{
			ml[j] = ft_substr(s, i, ft_lencount(s + i, c));
			if (!ml[j])
			{
				ft_free(ml);
				return (NULL);
			}
			i = i + ft_lencount(s + i, c);
			j++;
		}
		if (s[i] == c && s[i + 1] == c)
		{
			ml[j] = ft_strdup("");
			j++;
		}
	}
	return (ml[j] = NULL, ml);
}

char	**ft_split(char const *s, char c)
{
	char	**ml;

	if (!s)
		return (0);
	ml = malloc(sizeof(char *) * (ft_countw(s, c) + 1));
	if (ml == 0)
		return (0);
	return (split2(ml, s, c));
}
