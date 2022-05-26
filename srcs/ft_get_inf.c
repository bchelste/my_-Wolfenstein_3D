/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_inf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:46:20 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 15:52:19 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_get_res(char *s, t_str *str)
{
	int			i;

	i = 0;
	str->chk.am_res++;
	if (str->chk.am_res != 1)
		ft_put_message("wrong resolution in *.cub file");
	while (s[i] == ' ')
		i++;
	str->inf.r_wid = ft_atoi_cub(s + i);
	while ((s[i] >= '0') && (s[i] <= '9'))
		i++;
	while (s[i] == ' ')
		i++;
	str->inf.r_hei = ft_atoi_cub(s + i);
	if ((str->inf.r_wid <= 0) || (str->inf.r_hei <= 0))
		ft_put_message("wrong resolution in *.cub file");
	while ((s[i] >= '0') && (s[i] <= '9'))
		i++;
	if (s[i] != '\0')
		ft_put_message("there are extra symbols in resolution");
}

static void		ft_get_floor_colour(char *s, t_str *str)
{
	int			i;

	i = 0;
	str->chk.am_f++;
	if (str->chk.am_f != 1)
		ft_put_message("wrong floor colour in *.cub file");
	while ((s[i] == ' ') || (s[i] == '\t'))
		i++;
	str->inf.col_r_f = ft_atoi_cub(s + i);
	while ((s[i] >= '0') && (s[i] <= '9'))
		i++;
	while ((s[i] == ' ') || (s[i] == ','))
		i++;
	str->inf.col_g_f = ft_atoi_cub(s + i);
	while ((s[i] >= '0') && (s[i] <= '9'))
		i++;
	while ((s[i] == ' ') || (s[i] == ','))
		i++;
	str->inf.col_b_f = ft_atoi_cub(s + i);
	if (((str->inf.col_r_f > 255) || (str->inf.col_r_f <= 0)) ||
	((str->inf.col_g_f > 255) || (str->inf.col_g_f <= 0)) ||
	((str->inf.col_b_f > 255) || (str->inf.col_b_f <= 0)))
		ft_put_message("wrong floor RGB colour in *cub file");
	ft_extra_symbols_colour(s, i);
}

static void		ft_get_ceiling_colour(char *s, t_str *str)
{
	int			i;

	i = 0;
	str->chk.am_c++;
	if (str->chk.am_c != 1)
		ft_put_message("wrong floor colour in *.cub file");
	while (s[i] == ' ')
		i++;
	str->inf.col_r_c = ft_atoi_cub(s + i);
	while ((s[i] >= '0') && (s[i] <= '9'))
		i++;
	while ((s[i] == ' ') || (s[i] == ','))
		i++;
	str->inf.col_g_c = ft_atoi_cub(s + i);
	while ((s[i] >= '0') && (s[i] <= '9'))
		i++;
	while ((s[i] == ' ') || (s[i] == ','))
		i++;
	str->inf.col_b_c = ft_atoi_cub(s + i);
	if (((str->inf.col_r_c > 255) || (str->inf.col_r_c <= 0)) ||
	((str->inf.col_g_c > 255) || (str->inf.col_g_c <= 0)) ||
	((str->inf.col_b_c > 255) || (str->inf.col_b_c <= 0)))
		ft_put_message("wrong ceiling RGB colour in *cub file");
	ft_extra_symbols_colour(s, i);
}

void			ft_get_inf(char *s, t_str *str)
{
	int			i;

	i = 0;
	if (s == NULL)
		return ;
	if ((s[i] == 'R') && (s[i + 1] == ' '))
		ft_get_res((s + i + 1), str);
	else if ((s[i] == 'N') && (s[i + 1] == 'O') && (s[i + 2] == ' '))
		ft_get_no_path((s + 2), str);
	else if ((s[i] == 'S') && (s[i + 1] == 'O') && (s[i + 2] == ' '))
		ft_get_so_path((s + 2), str);
	else if ((s[i] == 'E') && (s[i + 1] == 'A') && (s[i + 2] == ' '))
		ft_get_ea_path((s + 2), str);
	else if ((s[i] == 'W') && (s[i + 1] == 'E') && (s[i + 2] == ' '))
		ft_get_we_path((s + 2), str);
	else if ((s[i] == 'S') && (s[i + 1] == ' '))
		ft_get_s_path((s + 1), str);
	else if ((s[i] == 'C') && (s[i + 1] == ' '))
		ft_get_ceiling_colour((s + 1), str);
	else if ((s[i] == 'F') && (s[i + 1] == ' '))
		ft_get_floor_colour((s + 1), str);
	else
		ft_put_message("The file *.cub is not valid!");
	free(s);
}

void			ft_get_map(t_list *list, t_str *str)
{
	int			i;
	t_list		*tmp;

	i = 0;
	str->inf.map = (char**)malloc(sizeof(char*) * (ft_lstsize(list) + 1));
	if (str->inf.map == NULL)
		ft_put_message("malloc error\n");
	if (list == NULL)
		ft_put_message("There is no map in *.cub file");
	while (list != NULL)
	{
		tmp = list->next;
		str->inf.map[i] = ft_strdup((char*)list->content);
		ft_lstdelone(list, &free);
		list = tmp;
		i++;
	}
	str->inf.map[i] = NULL;
}
