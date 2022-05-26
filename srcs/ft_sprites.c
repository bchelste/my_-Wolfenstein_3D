/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:03:57 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/25 00:52:08 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_transform_sprt(t_str *str)
{
	str->dda.inv_det = 1.0 / (str->plr.pln_x * str->plr.dir_y -
		str->plr.pln_y * str->plr.dir_x);
	str->dda.trform_x = str->dda.inv_det * (str->plr.dir_y * str->dda.sprt_x -
		str->plr.dir_x * str->dda.sprt_y);
	str->dda.trform_y = str->dda.inv_det * (str->plr.pln_x * str->dda.sprt_y -
		str->plr.pln_y * str->dda.sprt_x);
	str->dda.sprt_scr_x = (int)((str->inf.r_wid / 2) *
		(1 + str->dda.trform_x / str->dda.trform_y));
}

static void	ft_size_sprt(t_str *str)
{
	double	ratio;

	ratio = (double)(str->inf.scr_h) / str->inf.scr_w;
	str->dda.sprt_hei = abs((int)((str->inf.r_wid / str->dda.trform_y) *
		ratio));
	str->dda.sprt_strt_y = str->inf.r_hei / 2 - str->dda.sprt_hei / 2;
	if (str->dda.sprt_strt_y < 0)
		str->dda.sprt_strt_y = 0;
	str->dda.sprt_end_y = str->dda.sprt_hei / 2 + str->inf.r_hei / 2;
	if (str->dda.sprt_end_y >= str->inf.r_hei)
		str->dda.sprt_end_y = str->inf.r_hei - 1;
	str->dda.sprt_wid = abs((int)((str->inf.r_wid / str->dda.trform_y) *
		ratio));
	str->dda.sprt_strt_x = str->dda.sprt_scr_x - str->dda.sprt_wid / 2;
	if (str->dda.sprt_strt_x < 0)
		str->dda.sprt_strt_x = 0;
	str->dda.sprt_end_x = str->dda.sprt_wid / 2 + str->dda.sprt_scr_x;
	if (str->dda.sprt_end_x >= str->inf.r_wid)
		str->dda.sprt_end_x = str->inf.r_wid - 1;
}

static void	ft_loop_through_utils(t_str *str, int i, int j)
{
	int		d;
	int		pix;

	d = j * 256 - str->inf.r_hei * 128 + str->dda.sprt_hei * 128;
	str->dda.sprt_ty = ((d * str->cub.s_h) / str->dda.sprt_hei) / 256;
	pix = col_pix(&str->cub.s_sprt, str->dda.sprt_tx, str->dda.sprt_ty);
	if ((pix & 0x00FFFFFF) != 0)
		my_mlx_pixel_put(str, i, j, pix);
}

static void	ft_loop_through(t_str *str)
{
	int		i;
	int		j;

	i = str->dda.sprt_strt_x;
	while (i < str->dda.sprt_end_x)
	{
		str->dda.sprt_tx = (int)((256 * (i - (str->dda.sprt_scr_x -
			str->dda.sprt_wid / 2)) * str->cub.s_w / str->dda.sprt_wid) / 256);
		if ((str->dda.trform_y > 0) && (i > 0) && (i < str->inf.r_wid) &&
			(str->dda.trform_y < str->dda.buf[i]))
		{
			j = str->dda.sprt_strt_y;
			while (j < str->dda.sprt_end_y)
			{
				ft_loop_through_utils(str, i, j);
				j++;
			}
		}
		i++;
	}
}

void		ft_sprites(t_str *str)
{
	int		i;

	i = 0;
	while (i < str->inf.am_sprt)
	{
		str->inf.sprt[i].sprt_dist = (str->plr.pos_x - str->inf.sprt[i].x) *
			(str->plr.pos_x - str->inf.sprt[i].x) +
			(str->plr.pos_y - str->inf.sprt[i].y) *
			(str->plr.pos_y - str->inf.sprt[i].y);
		i++;
	}
	ft_sort_sprites(str);
	i = 0;
	while (i < str->inf.am_sprt)
	{
		str->dda.sprt_x = str->inf.sprt[i].x - str->plr.pos_x + 0.5;
		str->dda.sprt_y = str->inf.sprt[i].y - str->plr.pos_y + 0.5;
		ft_transform_sprt(str);
		ft_size_sprt(str);
		ft_loop_through(str);
		i++;
	}
}
