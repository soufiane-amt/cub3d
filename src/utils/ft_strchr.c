/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:20:58 by akadi             #+#    #+#             */
/*   Updated: 2023/01/03 17:20:25 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *)s;
	while (*src != (char)c)
	{
		if (*src == '\0')
			return (NULL);
		src++;
	}
	return (src);
}
