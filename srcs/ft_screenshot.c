/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:57:43 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 23:36:24 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_file_header(t_str *str, int fd)
{
	int			tmp;
	int			r;

	r = write(fd, "B", 1);
	r = write(fd, "M", 1);
	tmp = 14 + 40 + (str->inf.r_hei * str->inf.r_wid * 4);
	r = write(fd, &tmp, 4);
	tmp = 0;
	r = write(fd, &tmp, 2);
	r = write(fd, &tmp, 2);
	tmp = 14 + 40;
	r = write(fd, &tmp, 4);
	r++;
}

static void		ft_info_header(t_str *str, int fd)
{
	int			tmp;
	int			r;
	int			i;

	i = 0;
	tmp = 40;
	r = write(fd, &tmp, 4);
	tmp = str->inf.r_wid;
	r = write(fd, &tmp, 4);
	tmp = str->inf.r_hei;
	r = write(fd, &tmp, 4);
	tmp = 1;
	r = write(fd, &tmp, 2);
	tmp = 4 * 8;
	r = write(fd, &tmp, 2);
	tmp = 0;
	while (i < 5)
	{
		r = write(fd, &tmp, 4);
		i++;
	}
	r++;
}

static void		ft_bmp(t_str *str, int fd)
{
	int			i;
	int			j;
	int			r;
	int			tmp;

	ft_file_header(str, fd);
	ft_info_header(str, fd);
	i = str->inf.r_hei;
	while (i > 0)
	{
		j = 0;
		while (j < str->inf.r_wid)
		{
			tmp = col_pix(&str->cub.img, j, i);
			r = write(fd, &tmp, 4);
			if (r < 0)
				ft_put_message("bmp error");
			j++;
		}
		i--;
	}
}

void			ft_screenshot(t_str *str, char *argv1)
{
	int			fd;

	fd = open(argv1, O_RDONLY);
	if (fd < 0)
		ft_put_message("reading error");
	ft_parser_inf(fd, str);
	str->cub.img.img = mlx_new_image(str->cub.mlx,
		str->inf.r_wid, str->inf.r_hei);
	if (str->cub.img.img == NULL)
		ft_put_message("allocation error");
	str->cub.img.addr = mlx_get_data_addr(str->cub.img.img, &str->cub.img.bpp,
										&str->cub.img.l_l, &str->cub.img.end);
	ft_images(str);
	ft_set_plr_params(str);
	ft_start(str);
	close(fd);
	fd = 0;
	fd = open("cub3D.bmp", O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		ft_put_message("error in creating bmp file");
	ft_bmp(str, fd);
	close(fd);
	mlx_destroy_image(str->cub.mlx, str->cub.img.img);
	ft_free_exit(str);
	exit(EXIT_SUCCESS);
}
