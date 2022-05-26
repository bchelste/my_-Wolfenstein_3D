/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:12:15 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 02:57:45 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_init_keys(t_str *str)
{
	str->keys.w = 0;
	str->keys.s = 0;
	str->keys.d = 0;
	str->keys.a = 0;
	str->keys.rght = 0;
	str->keys.lft = 0;
}

void		ft_check_keys(t_str *str)
{
	if (str->keys.w == 1)
		ft_plr_mv_frnt(str);
	if (str->keys.s == 1)
		ft_plr_mv_bck(str);
	if (str->keys.d == 1)
		ft_plr_mv_rght(str);
	if (str->keys.a == 1)
		ft_plr_mv_lft(str);
	if (str->keys.rght == 1)
		ft_plr_rot_rght(str);
	if (str->keys.lft == 1)
		ft_plr_rot_lft(str);
}

int			ft_press_key(int keycode, t_str *str)
{
	if (keycode == W_KEY)
		str->keys.w = 1;
	if (keycode == S_KEY)
		str->keys.s = 1;
	if (keycode == D_KEY)
		str->keys.d = 1;
	if (keycode == A_KEY)
		str->keys.a = 1;
	if (keycode == RGHT_KEY)
		str->keys.rght = 1;
	if (keycode == LFT_KEY)
		str->keys.lft = 1;
	if (keycode == ESC_KEY)
		ft_close_win(str);
	return (0);
}

int			ft_release_key(int keycode, t_str *str)
{
	if (keycode == W_KEY)
		str->keys.w = 0;
	if (keycode == S_KEY)
		str->keys.s = 0;
	if (keycode == D_KEY)
		str->keys.d = 0;
	if (keycode == A_KEY)
		str->keys.a = 0;
	if (keycode == RGHT_KEY)
		str->keys.rght = 0;
	if (keycode == LFT_KEY)
		str->keys.lft = 0;
	return (0);
}
