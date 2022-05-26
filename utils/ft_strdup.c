/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:20:39 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 15:19:48 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

char	*ft_strdup(char *str)
{
	char	*p;
	int		i;

	i = 0;
	p = (char*)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (str[i] != 0)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
