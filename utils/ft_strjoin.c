/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:31:36 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/15 00:23:06 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	p = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (NULL);
	str = p;
	while (*s1 != '\0')
	{
		*p = *s1;
		p++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*p = *s2;
		p++;
		s2++;
	}
	*p = '\0';
	return (str);
}
