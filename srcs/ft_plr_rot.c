/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plr_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:53:14 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 02:54:30 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_plr_rot_lft(t_str *str)
{
	double		olddirx;
	double		oldplanex;

	olddirx = str->plr.dir_x;
	str->plr.dir_x = str->plr.dir_x * cos(-ROT_SPEED) -
		str->plr.dir_y * sin(-ROT_SPEED);
	str->plr.dir_y = olddirx * sin(-ROT_SPEED) +
		str->plr.dir_y * cos(-ROT_SPEED);
	oldplanex = str->plr.pln_x;
	str->plr.pln_x = str->plr.pln_x * cos(-ROT_SPEED) -
		str->plr.pln_y * sin(-ROT_SPEED);
	str->plr.pln_y = oldplanex * sin(-ROT_SPEED) +
		str->plr.pln_y * cos(-ROT_SPEED);
}

void			ft_plr_rot_rght(t_str *str)
{
	double		olddirx;
	double		oldplanex;

	olddirx = str->plr.dir_x;
	str->plr.dir_x = str->plr.dir_x * cos(ROT_SPEED) -
		str->plr.dir_y * sin(ROT_SPEED);
	str->plr.dir_y = olddirx * sin(ROT_SPEED) +
		str->plr.dir_y * cos(ROT_SPEED);
	oldplanex = str->plr.pln_x;
	str->plr.pln_x = str->plr.pln_x * cos(ROT_SPEED) -
		str->plr.pln_y * sin(ROT_SPEED);
	str->plr.pln_y = oldplanex * sin(ROT_SPEED) +
		str->plr.pln_y * cos(ROT_SPEED);
}
