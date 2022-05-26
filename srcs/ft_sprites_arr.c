/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:15:31 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/25 00:51:27 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_amnt_sprt(t_str *str)
{
	int			i;
	int			j;
	int			n;

	n = 0;
	i = 0;
	while (str->inf.map[i] != NULL)
	{
		j = 0;
		while (str->inf.map[i][j] != '\0')
		{
			if (str->inf.map[i][j] == '2')
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

void			ft_creat_sprt_arr(t_str *str)
{
	int			i;
	int			j;

	str->inf.sprt = (t_sprt*)malloc(sizeof(t_sprt) * (ft_amnt_sprt(str) + 1));
	if (str->inf.sprt == NULL)
		ft_put_message("malloc error");
	i = 0;
	while (str->inf.map[i] != NULL)
	{
		j = 0;
		while (str->inf.map[i][j] != '\0')
		{
			if (str->inf.map[i][j] == '2')
			{
				str->inf.sprt[str->inf.am_sprt].x = j;
				str->inf.sprt[str->inf.am_sprt].y = i;
				str->inf.am_sprt++;
			}
			j++;
		}
		i++;
	}
}

void			ft_sort_sprites(t_str *str)
{
	int			i;
	t_sprt		tmp;

	i = 0;
	while ((i + 1) < str->inf.am_sprt)
	{
		if (str->inf.sprt[i].sprt_dist < str->inf.sprt[i + 1].sprt_dist)
		{
			tmp = str->inf.sprt[i];
			str->inf.sprt[i] = str->inf.sprt[i + 1];
			str->inf.sprt[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}
