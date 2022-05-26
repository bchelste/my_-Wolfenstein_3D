/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:52:36 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 16:13:34 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_put_message(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}

int			ft_close_win(t_str *str)
{
	mlx_destroy_window(str->cub.mlx, str->cub.win);
	ft_free_exit(str);
	exit(EXIT_SUCCESS);
	return (0);
}

int			ft_play(t_str *str)
{
	ft_check_keys(str);
	str->cub.img.img = mlx_new_image(str->cub.mlx,
		str->inf.r_wid, str->inf.r_hei);
	if (str->cub.img.img == NULL)
		ft_put_message("allocation error");
	str->cub.img.addr = mlx_get_data_addr(str->cub.img.img, &str->cub.img.bpp,
										&str->cub.img.l_l, &str->cub.img.end);
	ft_start(str);
	mlx_put_image_to_window(str->cub.mlx, str->cub.win,
		str->cub.img.img, 0, 0);
	mlx_do_sync(str->cub.mlx);
	mlx_destroy_image(str->cub.mlx, str->cub.img.img);
	return (0);
}

static void	ft_params(t_str *str, double diry, double plane_x, double plane_y)
{
	str->plr.dir_y = diry;
	str->plr.pln_x = plane_x;
	str->plr.pln_y = plane_y;
}

void		ft_set_plr_params(t_str *str)
{
	str->plr.pos_x = (double)str->inf.st_x;
	str->plr.pos_y = (double)str->inf.st_y;
	if (str->inf.map[str->inf.st_y][str->inf.st_x] == 'N')
	{
		ft_params(str, -1.0, 0.66, 0.0);
		str->plr.dir_x = 0.0;
	}
	if (str->inf.map[str->inf.st_y][str->inf.st_x] == 'S')
	{
		ft_params(str, 1.0, -0.66, 0.0);
		str->plr.dir_x = 0.0;
	}
	if (str->inf.map[str->inf.st_y][str->inf.st_x] == 'E')
	{
		ft_params(str, 0.0, 0.0, -0.66);
		str->plr.dir_x = -1.0;
	}
	if (str->inf.map[str->inf.st_y][str->inf.st_x] == 'W')
	{
		ft_params(str, 0.0, 0.0, 0.66);
		str->plr.dir_x = 1.0;
	}
	str->inf.map[str->inf.st_y][str->inf.st_x] = '0';
}
