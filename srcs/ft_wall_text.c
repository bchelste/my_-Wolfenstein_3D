/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:45:36 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 20:13:25 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_wall_no_text(t_str *str)
{
	int		i;

	str->dda.text_x = (int)(str->dda.wall_x * (double)str->cub.no_w);
	if ((str->dda.side == 1) && (str->dda.rd_y > 0))
		str->dda.text_x = str->cub.no_w - str->dda.text_x - 1;
	str->dda.step = 1.0 * str->cub.no_h / str->dda.ln_hei;
	str->dda.text_pos = (str->dda.dr_strt -
		str->inf.r_hei / 2 + str->dda.ln_hei / 2) * str->dda.step;
	i = str->dda.dr_strt;
	while (i < str->dda.dr_end)
	{
		str->dda.text_y = (int)str->dda.text_pos & (str->cub.no_h - 1);
		str->dda.text_pos = str->dda.text_pos + str->dda.step;
		my_mlx_pixel_put(str, str->dda.x, i, col_pix(&str->cub.no_wall,
			str->dda.text_x, str->dda.text_y));
		i++;
	}
}

void		ft_wall_so_text(t_str *str)
{
	int		i;

	str->dda.text_x = (int)(str->dda.wall_x * (double)str->cub.so_w);
	if ((str->dda.side == 1) && (str->dda.rd_y > 0))
		str->dda.text_x = str->cub.so_w - str->dda.text_x - 1;
	str->dda.step = 1.0 * str->cub.so_h / str->dda.ln_hei;
	str->dda.text_pos = (str->dda.dr_strt -
		str->inf.r_hei / 2 + str->dda.ln_hei / 2) * str->dda.step;
	i = str->dda.dr_strt;
	while (i < str->dda.dr_end)
	{
		str->dda.text_y = (int)str->dda.text_pos & (str->cub.so_h - 1);
		str->dda.text_pos = str->dda.text_pos + str->dda.step;
		my_mlx_pixel_put(str, str->dda.x, i, col_pix(&str->cub.so_wall,
			str->dda.text_x, str->dda.text_y));
		i++;
	}
}

void		ft_wall_ea_text(t_str *str)
{
	int		i;

	str->dda.text_x = (int)(str->dda.wall_x * (double)str->cub.ea_w);
	if ((str->dda.side == 0) && (str->dda.rd_x < 0))
		str->dda.text_x = str->cub.ea_w - str->dda.text_x - 1;
	str->dda.step = 1.0 * str->cub.ea_h / str->dda.ln_hei;
	str->dda.text_pos = (str->dda.dr_strt -
		str->inf.r_hei / 2 + str->dda.ln_hei / 2) * str->dda.step;
	i = str->dda.dr_strt;
	while (i < str->dda.dr_end)
	{
		str->dda.text_y = (int)str->dda.text_pos & (str->cub.ea_h - 1);
		str->dda.text_pos = str->dda.text_pos + str->dda.step;
		my_mlx_pixel_put(str, str->dda.x, i, col_pix(&str->cub.ea_wall,
			str->dda.text_x, str->dda.text_y));
		i++;
	}
}

void		ft_wall_we_text(t_str *str)
{
	int		i;

	str->dda.text_x = (int)(str->dda.wall_x * (double)str->cub.we_w);
	if ((str->dda.side == 0) && (str->dda.rd_x < 0))
		str->dda.text_x = str->cub.we_w - str->dda.text_x - 1;
	str->dda.step = 1.0 * str->cub.we_h / str->dda.ln_hei;
	str->dda.text_pos = (str->dda.dr_strt -
		str->inf.r_hei / 2 + str->dda.ln_hei / 2) * str->dda.step;
	i = str->dda.dr_strt;
	while (i < str->dda.dr_end)
	{
		str->dda.text_y = (int)str->dda.text_pos & (str->cub.we_h - 1);
		str->dda.text_pos = str->dda.text_pos + str->dda.step;
		my_mlx_pixel_put(str, str->dda.x, i, col_pix(&str->cub.we_wall,
			str->dda.text_x, str->dda.text_y));
		i++;
	}
}
