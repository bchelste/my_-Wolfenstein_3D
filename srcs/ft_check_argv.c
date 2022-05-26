/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 03:10:20 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 03:10:23 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_chk_map_format(char *name)
{
	int	n;

	n = ft_strlen(name);
	if (name[n - 1] == 'b')
		if (name[n - 2] == 'u')
			if (name[n - 3] == 'c')
				if (name[n - 4] == '.')
				{
					return (1);
				}
	return (0);
}

int		ft_chk_save(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str2[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (0);
	}
	if (str1[i] != '\0')
		return (0);
	return (1);
}

void	ft_extra_symbols_colour(char *str, int i)
{
	while ((str[i] >= '0') && (str[i] <= '9'))
		i++;
	if (str[i])
		ft_put_message("there are extra symbols in colours");
}
