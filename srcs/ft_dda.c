/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:29:05 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/25 00:52:35 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_get_dda_param(t_str *str)
{
	if (str->dda.rd_x < 0)
	{
		str->dda.stp_x = -1;
		str->dda.sd_dst_x = (str->plr.pos_x - str->dda.map_x) *
			str->dda.dlt_dst_x;
	}
	else
	{
		str->dda.stp_x = 1;
		str->dda.sd_dst_x = (str->dda.map_x + 1.0 - str->plr.pos_x) *
			str->dda.dlt_dst_x;
	}
	if (str->dda.rd_y < 0)
	{
		str->dda.stp_y = -1;
		str->dda.sd_dst_y = (str->plr.pos_y - str->dda.map_y) *
			str->dda.dlt_dst_y;
	}
	else
	{
		str->dda.stp_y = 1;
		str->dda.sd_dst_y = (str->dda.map_y + 1.0 - str->plr.pos_y) *
			str->dda.dlt_dst_y;
	}
}

void		ft_dda(t_str *str)
{
	str->dda.hit = 0;
	str->dda.side = 0;
	while (str->dda.hit == 0)
	{
		if (str->dda.sd_dst_x < str->dda.sd_dst_y)
		{
			str->dda.sd_dst_x = str->dda.sd_dst_x + str->dda.dlt_dst_x;
			str->dda.map_x = str->dda.map_x + str->dda.stp_x;
			str->dda.side = 0;
		}
		else
		{
			str->dda.sd_dst_y = str->dda.sd_dst_y + str->dda.dlt_dst_y;
			str->dda.map_y = str->dda.map_y + str->dda.stp_y;
			str->dda.side = 1;
		}
		if (str->inf.map[str->dda.map_y][str->dda.map_x] == '1')
			str->dda.hit = 1;
	}
}

void		ft_dist_to_wall(t_str *str)
{
	if (str->dda.side == 0)
		str->dda.pwd = (str->dda.map_x - str->plr.pos_x +
			(1 - str->dda.stp_x) / 2) / str->dda.rd_x;
	else
		str->dda.pwd = (str->dda.map_y - str->plr.pos_y +
			(1 - str->dda.stp_y) / 2) / str->dda.rd_y;
}

void		ft_wall_hei(t_str *str)
{
	double	ratio;

	ratio = (double)(str->inf.scr_h) / str->inf.scr_w;
	str->dda.ln_hei = (int)((str->inf.r_wid / str->dda.pwd) * ratio);
	str->dda.dr_strt = (str->inf.r_hei / 2) - (str->dda.ln_hei / 2);
	if (str->dda.dr_strt < 0)
		str->dda.dr_strt = 0;
	str->dda.dr_end = (str->inf.r_hei / 2) + (str->dda.ln_hei / 2);
	if (str->dda.dr_end >= str->inf.r_hei)
		str->dda.dr_end = str->inf.r_hei - 1;
}

void		ft_text_param(t_str *str)
{
	if (str->dda.side == 0)
		str->dda.wall_x = str->plr.pos_y + str->dda.pwd * str->dda.rd_y;
	else
		str->dda.wall_x = str->plr.pos_x + str->dda.pwd * str->dda.rd_x;
	str->dda.wall_x = str->dda.wall_x - floor((str->dda.wall_x));
}
