/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:52:44 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 14:41:49 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_init_inf_struct(t_str *str)
{
	str->inf.r_hei = 0;
	str->inf.r_wid = 0;
	str->inf.col_r_c = 0;
	str->inf.col_g_c = 0;
	str->inf.col_b_c = 0;
	str->inf.col_r_f = 0;
	str->inf.col_g_f = 0;
	str->inf.col_b_f = 0;
	str->inf.t_path_no = NULL;
	str->inf.t_path_so = NULL;
	str->inf.t_path_ea = NULL;
	str->inf.t_path_we = NULL;
	str->inf.t_path_s = NULL;
	str->inf.map = NULL;
	str->inf.map_h = 0;
	str->inf.map_w = 0;
	str->inf.ar_mw = NULL;
	str->inf.st_x = 0;
	str->inf.st_y = 0;
	str->inf.am_sprt = 0;
	str->inf.sprt = NULL;
}

static void		ft_init_check_struct(t_str *str)
{
	str->chk.am_res = 0;
	str->chk.am_no = 0;
	str->chk.am_so = 0;
	str->chk.am_we = 0;
	str->chk.am_ea = 0;
	str->chk.am_s = 0;
	str->chk.am_f = 0;
	str->chk.am_c = 0;
	str->chk.am_pl = 0;
	str->chk.ff_ar = NULL;
}

static void		ft_init_cub_struct(t_str *str)
{
	str->cub.mlx = NULL;
	str->cub.win = NULL;
	str->cub.no_w = 0;
	str->cub.no_h = 0;
	str->cub.so_w = 0;
	str->cub.so_h = 0;
	str->cub.ea_w = 0;
	str->cub.ea_h = 0;
	str->cub.we_w = 0;
	str->cub.we_h = 0;
	str->cub.s_w = 0;
	str->cub.s_h = 0;
	str->cub.img.img = NULL;
	str->cub.img.addr = NULL;
	str->cub.img.bpp = 0;
	str->cub.img.l_l = 0;
	str->cub.img.end = 0;
}

void			ft_init_structs(t_str *str)
{
	ft_init_inf_struct(str);
	ft_init_check_struct(str);
	ft_init_keys(str);
	ft_init_cub_struct(str);
	str->cub.mlx = mlx_init();
}
