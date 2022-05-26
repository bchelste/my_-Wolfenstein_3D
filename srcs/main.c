/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:24:38 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 22:00:17 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char **argv)
{
	t_str	str;

	if (argc == 2)
	{
		if (ft_chk_map_format(argv[1]) != 1)
			ft_put_message("wrong map format");
		if ((ft_check_file(argv[1])) == 0)
			ft_put_message("this is not a map");
		ft_init_structs(&str);
		ft_parser_inf(open(argv[1], O_RDONLY), &str);
		ft_cub3d_start(&str);
	}
	else if (argc == 3)
	{
		if ((ft_chk_map_format(argv[1]) != 1) ||
				((ft_chk_save(argv[2], "--save")) != 1))
			ft_put_message("wrong names of arguments");
		if ((ft_check_file(argv[1])) == 0)
			ft_put_message("this is not a map");
		ft_init_structs(&str);
		ft_screenshot(&str, argv[1]);
	}
	else
		ft_put_message("wrong number of arguments");
	return (0);
}
