/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:00:44 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 22:10:01 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_wall_text(t_str *str)
{
	if ((str->dda.side == 1) && (str->dda.stp_y < 0))
		ft_wall_no_text(str);
	else if ((str->dda.side == 1) && (str->dda.stp_y > 0))
		ft_wall_so_text(str);
	else if ((str->dda.side == 0) && (str->dda.stp_x < 0))
		ft_wall_we_text(str);
	else if ((str->dda.side == 0) && (str->dda.stp_x > 0))
		ft_wall_ea_text(str);
}

void		ft_floor(t_str *str)
{
	int		i;
	int		colour;

	i = str->dda.dr_end;
	colour = (0 << 24) | (str->inf.col_r_f << 16) |
			(str->inf.col_g_f << 8) | str->inf.col_b_f;
	while (i < (str->inf.r_hei - 1))
	{
		my_mlx_pixel_put(str, str->dda.x, i, colour);
		i++;
	}
}

void		ft_ceiling(t_str *str)
{
	int		i;
	int		colour;

	i = 0;
	colour = (0 << 24) | (str->inf.col_r_c << 16) |
			(str->inf.col_g_c << 8) | str->inf.col_b_c;
	while (i < str->dda.dr_strt)
	{
		my_mlx_pixel_put(str, str->dda.x, i, colour);
		i++;
	}
}

void		ft_drawing(t_str *str)
{
	str->dda.x = 0;
	while (str->dda.x < str->inf.r_wid)
	{
		str->dda.camera_x = 2 * str->dda.x / (double)str->inf.r_wid - 1;
		str->dda.rd_x = str->plr.dir_x + str->plr.pln_x * str->dda.camera_x;
		str->dda.rd_y = str->plr.dir_y + str->plr.pln_y * str->dda.camera_x;
		str->dda.map_x = (int)floor(str->plr.pos_x);
		str->dda.map_y = (int)floor(str->plr.pos_y);
		str->dda.dlt_dst_x = fabs(1 / str->dda.rd_x);
		str->dda.dlt_dst_y = fabs(1 / str->dda.rd_y);
		ft_get_dda_param(str);
		ft_dda(str);
		ft_dist_to_wall(str);
		ft_wall_hei(str);
		ft_text_param(str);
		ft_wall_text(str);
		ft_floor(str);
		ft_ceiling(str);
		str->dda.buf[str->dda.x] = str->dda.pwd;
		str->dda.x++;
	}
}

void		ft_start(t_str *str)
{
	str->dda.buf = (double*)malloc(sizeof(double) * str->inf.r_wid);
	if (str->dda.buf == NULL)
		ft_put_message("malloc error");
	ft_drawing(str);
	ft_sprites(str);
	free(str->dda.buf);
}
