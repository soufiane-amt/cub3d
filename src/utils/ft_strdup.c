/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:22:38 by akadi             #+#    #+#             */
/*   Updated: 2022/12/28 22:48:32 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	len;
	char	*dp;
	int		i;

	ss = (char *)s;
	len = ft_strlen(ss);
	i = 0;
	dp = (char *)malloc((len + 1) * sizeof(char));
	if (dp == NULL)
		return (NULL);
	while (ss[i] != '\0')
	{
		dp[i] = ss[i];
		i++;
	}
	dp[i] = '\0';
	return (dp);
}
