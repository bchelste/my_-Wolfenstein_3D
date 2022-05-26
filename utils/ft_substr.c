/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:31:29 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 15:10:46 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((int)start >= ft_strlen(s))
	{
		sub = (char*)malloc(sizeof(char));
		if (sub == NULL)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	sub = (char*)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while ((s[start + i] != '\0') && (len > 0))
	{
		sub[i] = s[start + i];
		i++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}
