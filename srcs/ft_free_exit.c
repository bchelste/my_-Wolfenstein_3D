/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 00:46:03 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 16:15:31 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_free_parser(t_str *str)
{
	int		i;

	if (str->inf.t_path_no != NULL)
		free(str->inf.t_path_no);
	if (str->inf.t_path_so != NULL)
		free(str->inf.t_path_so);
	if (str->inf.t_path_ea != NULL)
		free(str->inf.t_path_ea);
	if (str->inf.t_path_we != NULL)
		free(str->inf.t_path_we);
	if (str->inf.t_path_s != NULL)
		free(str->inf.t_path_s);
	if (str->inf.ar_mw != NULL)
		free(str->inf.ar_mw);
	if (str->inf.sprt != NULL)
		free(str->inf.sprt);
	if (str->inf.map != NULL)
	{
		i = 0;
		while (str->inf.map[i] != NULL)
			free(str->inf.map[i++]);
		free(str->inf.map);
	}
}

void			ft_free_exit(t_str *str)
{
	int			i;

	ft_free_parser(str);
	if (str->chk.ff_ar != NULL)
	{
		i = 0;
		while (str->chk.ff_ar[i] != NULL)
			free(str->chk.ff_ar[i++]);
		free(str->chk.ff_ar);
	}
	mlx_destroy_image(str->cub.mlx, str->cub.no_wall.img);
	mlx_destroy_image(str->cub.mlx, str->cub.so_wall.img);
	mlx_destroy_image(str->cub.mlx, str->cub.ea_wall.img);
	mlx_destroy_image(str->cub.mlx, str->cub.we_wall.img);
	mlx_destroy_image(str->cub.mlx, str->cub.s_sprt.img);
	mlx_destroy_display(str->cub.mlx);
	free(str->cub.mlx);
}

int				ft_check_file(char *argv1)
{
	int			fd;
	int			r;
	char		buf[50];

	fd = open(argv1, O_RDONLY);
	r = read(fd, buf, 50);
	if (r < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
