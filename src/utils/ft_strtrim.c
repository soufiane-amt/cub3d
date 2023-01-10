/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:38:31 by akadi             #+#    #+#             */
/*   Updated: 2022/12/28 22:46:22 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	first_position(char *s1, const char *set1)
{
	size_t	l;
	size_t	j;

	j = 0;
	l = ft_strlen(s1);
	while (j < l)
	{
		if (ft_strchr(set1, s1[j]) == 0)
			break ;
		j++;
	}
	return (j);
}

static size_t	last_position(char *s2, const char *set2)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = ft_strlen(s2);
	while (i < k)
	{
		if (ft_strchr(set2, s2[k - i - 1]) == 0)
			break ;
		i++;
	}
	return (k - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*src;
	char	*trim;
	int		i;
	int		len;
	int		start;

	trim = NULL;
	if (!s1 || !set)
		return (NULL);
	src = (char *)s1;
	if (first_position(src, set) == ft_strlen(src))
		return (ft_strdup(""));
	if (src != NULL)
	{
		i = 0;
		len = ((last_position(src, set)) - (first_position(src, set)) + 1);
		trim = (char *)malloc(len * sizeof(char));
		if (!trim)
			return (NULL);
		start = first_position(src, set);
		while (i < len - 1)
			trim[i++] = src[start++];
		trim[i] = '\0';
	}
	return (trim);
}
