/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:15:47 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 14:37:49 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_str *str, int x, int y, int colour)
{
	char	*dst;

	dst = (void*)str->cub.img.addr +
		(y * str->cub.img.l_l + x * (str->cub.img.bpp / 8));
	*(int*)dst = colour;
}

int			col_pix(t_data *img, int x, int y)
{
	char	*dst;
	int		color;

	dst = img->addr + (y * img->l_l + x * (img->bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void		ft_images(t_str *str)
{
	ft_no_text_to_img(str);
	ft_so_text_to_img(str);
	ft_ea_text_to_img(str);
	ft_we_text_to_img(str);
	ft_s_text_to_img(str);
}

void		ft_cub3d_start(t_str *str)
{
	str->cub.win = mlx_new_window(str->cub.mlx, str->inf.r_wid, str->inf.r_hei,
										"cub3D");
	if (str->cub.win == NULL)
		ft_put_message("allocation error");
	str->cub.img.img = mlx_new_image(str->cub.mlx,
		str->inf.r_wid, str->inf.r_hei);
	if (str->cub.img.img == NULL)
		ft_put_message("allocation error");
	str->cub.img.addr = mlx_get_data_addr(str->cub.img.img, &str->cub.img.bpp,
										&str->cub.img.l_l, &str->cub.img.end);
	ft_images(str);
	ft_set_plr_params(str);
	ft_start(str);
	mlx_put_image_to_window(str->cub.mlx, str->cub.win,
		str->cub.img.img, 0, 0);
	mlx_destroy_image(str->cub.mlx, str->cub.img.img);
	mlx_hook(str->cub.win, 33, 0L, ft_close_win, str);
	mlx_hook(str->cub.win, 2, 1L << 0, ft_press_key, str);
	mlx_hook(str->cub.win, 3, 1L << 1, ft_release_key, str);
	mlx_loop_hook(str->cub.mlx, ft_play, str);
	mlx_loop(str->cub.mlx);
}
