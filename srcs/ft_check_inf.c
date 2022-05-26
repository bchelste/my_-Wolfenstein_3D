/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:57:45 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 21:26:14 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_check_pl_pos(t_str *str)
{
	int			i;
	int			j;

	if (str->chk.am_pl > 1)
		ft_put_message("There are more then 1 player on the map");
	str->inf.st_x = 0;
	str->inf.st_y = 0;
	i = 0;
	while (str->inf.map[i] != NULL)
	{
		j = 0;
		while (str->inf.map[i][j] != '\0')
		{
			if ((str->inf.map[i][j] == 'N') || (str->inf.map[i][j] == 'S') ||
			(str->inf.map[i][j] == 'E') || (str->inf.map[i][j] == 'W'))
			{
				str->chk.am_pl++;
				str->inf.st_x = j;
				str->inf.st_y = i;
			}
			j++;
		}
		i++;
	}
}

static void		ft_check_map_symb(t_str *str)
{
	int			i;
	int			j;

	i = 0;
	while (str->inf.map[i] != NULL)
	{
		j = 0;
		while (str->inf.map[i][j] != '\0')
		{
			if ((str->inf.map[i][j] != 'N') && (str->inf.map[i][j] != 'S') &&
			(str->inf.map[i][j] != 'E') && (str->inf.map[i][j] != 'W') &&
			(str->inf.map[i][j] != '0') && (str->inf.map[i][j] != '1') &&
			(str->inf.map[i][j] != '2') && (str->inf.map[i][j] != ' '))
				ft_put_message("There are wrong symbols in the map");
			j++;
		}
		if (j > str->inf.map_w)
			str->inf.map_w = j;
		i++;
	}
	str->inf.map_h = i;
}

static void		ft_arr_map_width(t_str *str)
{
	int			i;

	i = 0;
	str->inf.ar_mw = (int*)malloc(sizeof(int) * (str->inf.map_h));
	while (i < str->inf.map_h)
	{
		str->inf.ar_mw[i] = ft_strlen(str->inf.map[i]);
		i++;
	}
}

void			ft_resolution(t_str *str)
{
	mlx_get_screen_size(str->cub.mlx, &str->inf.scr_w, &str->inf.scr_h);
	if (str->inf.r_hei >= str->inf.scr_h)
		str->inf.r_hei = str->inf.scr_h;
	if (str->inf.r_wid >= str->inf.scr_w)
		str->inf.r_wid = str->inf.scr_w;
}

void			ft_check_inf(t_str *str)
{
	ft_check_map_symb(str);
	ft_arr_map_width(str);
	ft_check_pl_pos(str);
	ft_check_ff_map(str);
	ft_creat_sprt_arr(str);
	ft_resolution(str);
	if ((str->chk.am_res != 1) || (str->chk.am_no != 1) ||
	(str->chk.am_so != 1) || (str->chk.am_we != 1) ||
	(str->chk.am_ea != 1) || (str->chk.am_s != 1) ||
	(str->chk.am_f != 1) || (str->chk.am_c != 1) || (str->chk.am_pl != 1))
		ft_put_message("The file *.cub is not valid");
}
