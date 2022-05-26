/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:10:59 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 02:47:39 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_no_text_to_img(t_str *str)
{
	str->cub.no_wall.img = mlx_xpm_file_to_image(str->cub.mlx,
		str->inf.t_path_no, &str->cub.no_w, &str->cub.no_h);
	if (str->cub.no_wall.img == NULL)
		ft_put_message("wrong path to NO texture");
	str->cub.no_wall.addr = mlx_get_data_addr(str->cub.no_wall.img,
	&str->cub.no_wall.bpp, &str->cub.no_wall.l_l, &str->cub.no_wall.end);
}

void		ft_so_text_to_img(t_str *str)
{
	str->cub.so_wall.img = mlx_xpm_file_to_image(str->cub.mlx,
		str->inf.t_path_so, &str->cub.so_w, &str->cub.so_h);
	if (str->cub.so_wall.img == NULL)
		ft_put_message("wrong path to SO texture");
	str->cub.so_wall.addr = mlx_get_data_addr(str->cub.so_wall.img,
	&str->cub.so_wall.bpp, &str->cub.so_wall.l_l, &str->cub.so_wall.end);
}

void		ft_ea_text_to_img(t_str *str)
{
	str->cub.ea_wall.img = mlx_xpm_file_to_image(str->cub.mlx,
		str->inf.t_path_ea, &str->cub.ea_w, &str->cub.ea_h);
	if (str->cub.ea_wall.img == NULL)
		ft_put_message("wrong path to EA texture");
	str->cub.ea_wall.addr = mlx_get_data_addr(str->cub.ea_wall.img,
	&str->cub.ea_wall.bpp, &str->cub.ea_wall.l_l, &str->cub.ea_wall.end);
}

void		ft_we_text_to_img(t_str *str)
{
	str->cub.we_wall.img = mlx_xpm_file_to_image(str->cub.mlx,
		str->inf.t_path_we, &str->cub.we_w, &str->cub.we_h);
	if (str->cub.we_wall.img == NULL)
		ft_put_message("wrong path to WE texture");
	str->cub.we_wall.addr = mlx_get_data_addr(str->cub.we_wall.img,
	&str->cub.we_wall.bpp, &str->cub.we_wall.l_l, &str->cub.we_wall.end);
}

void		ft_s_text_to_img(t_str *str)
{
	str->cub.s_sprt.img = mlx_xpm_file_to_image(str->cub.mlx,
		str->inf.t_path_s, &str->cub.s_w, &str->cub.s_h);
	if (str->cub.s_sprt.img == NULL)
		ft_put_message("wrong path to S texture");
	str->cub.s_sprt.addr = mlx_get_data_addr(str->cub.s_sprt.img,
	&str->cub.s_sprt.bpp, &str->cub.s_sprt.l_l, &str->cub.s_sprt.end);
}
