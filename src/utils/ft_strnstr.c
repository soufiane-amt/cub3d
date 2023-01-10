/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:32:24 by akadi             #+#    #+#             */
/*   Updated: 2022/12/28 22:46:06 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*src;
	char	*to_find;
	size_t	i;
	size_t	j;

	src = (char *)haystack;
	to_find = (char *)needle;
	i = 0;
	if (ft_strlen(src) < ft_strlen(to_find))
		return (NULL);
	if (*to_find == '\0')
		return (src);
	while ((src[i] != '\0') && (i < len))
	{
		j = 0;
		while ((to_find[j] != '\0') && ((to_find[j] == src[i + j]) && (i
					+ j < len)))
			j++;
		if ((to_find[j] == '\0') || (j == len))
			return (src + i);
		i++;
	}
	return (NULL);
}
