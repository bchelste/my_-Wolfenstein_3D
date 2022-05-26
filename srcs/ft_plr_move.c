/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plr_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:26:23 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 02:55:32 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_plr_mv_frnt(t_str *str)
{
	if (str->inf.map[(int)str->plr.pos_y]
	[(int)(str->plr.pos_x + str->plr.dir_x * MOVE_SPEED)] == '0')
		str->plr.pos_x = str->plr.pos_x + str->plr.dir_x * MOVE_SPEED;
	if (str->inf.map[(int)(str->plr.pos_y + str->plr.dir_y * MOVE_SPEED)]
	[(int)str->plr.pos_x] == '0')
		str->plr.pos_y = str->plr.pos_y + str->plr.dir_y * MOVE_SPEED;
}

void		ft_plr_mv_bck(t_str *str)
{
	if (str->inf.map[(int)str->plr.pos_y]
	[(int)(str->plr.pos_x - str->plr.dir_x * MOVE_SPEED)] == '0')
		str->plr.pos_x = str->plr.pos_x - str->plr.dir_x * MOVE_SPEED;
	if (str->inf.map[(int)(str->plr.pos_y - str->plr.dir_y * MOVE_SPEED)]
	[(int)str->plr.pos_x] == '0')
		str->plr.pos_y = str->plr.pos_y - str->plr.dir_y * MOVE_SPEED;
}

void		ft_plr_mv_lft(t_str *str)
{
	if (str->inf.map[(int)str->plr.pos_y]
	[(int)(str->plr.pos_x - str->plr.pln_x * MOVE_SPEED)] == '0')
		str->plr.pos_x = str->plr.pos_x - str->plr.pln_x * MOVE_SPEED;
	if (str->inf.map[(int)(str->plr.pos_y + str->plr.pln_y * MOVE_SPEED)]
	[(int)str->plr.pos_x] == '0')
		str->plr.pos_y = str->plr.pos_y - str->plr.pln_y * MOVE_SPEED;
}

void		ft_plr_mv_rght(t_str *str)
{
	if (str->inf.map[(int)str->plr.pos_y]
	[(int)(str->plr.pos_x + str->plr.pln_x * MOVE_SPEED)] == '0')
		str->plr.pos_x = str->plr.pos_x + str->plr.pln_x * MOVE_SPEED;
	if (str->inf.map[(int)(str->plr.pos_y + str->plr.pln_y * MOVE_SPEED)]
	[(int)str->plr.pos_x] == '0')
		str->plr.pos_y = str->plr.pos_y + str->plr.pln_y * MOVE_SPEED;
}
