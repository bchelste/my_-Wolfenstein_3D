/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_text_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:10:25 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 02:59:30 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_get_no_path(char *s, t_str *str)
{
	int			i;

	i = 0;
	str->chk.am_no++;
	if (str->chk.am_no != 1)
		ft_put_message("wrong amount of NO teture");
	while (s[i] == ' ')
		i++;
	str->inf.t_path_no = ft_strdup(s + i);
	if (str->inf.t_path_no == NULL)
		ft_put_message("something wrong with no_path to texture");
}

void			ft_get_so_path(char *s, t_str *str)
{
	int			i;

	i = 0;
	str->chk.am_so++;
	if (str->chk.am_so != 1)
		ft_put_message("wrong amount of SO teture");
	while (s[i] == ' ')
		i++;
	str->inf.t_path_so = ft_strdup(s + i);
	if (str->inf.t_path_so == NULL)
		ft_put_message("something wrong with no_path to texture");
}

void			ft_get_ea_path(char *s, t_str *str)
{
	int			i;

	i = 0;
	str->chk.am_ea++;
	if (str->chk.am_ea != 1)
		ft_put_message("wrong amount of EA teture");
	while (s[i] == ' ')
		i++;
	str->inf.t_path_ea = ft_strdup(s + i);
	if (str->inf.t_path_ea == NULL)
		ft_put_message("something wrong with no_path to texture");
}

void			ft_get_we_path(char *s, t_str *str)
{
	int			i;

	i = 0;
	str->chk.am_we++;
	if (str->chk.am_we != 1)
		ft_put_message("wrong amount of WE teture");
	while (s[i] == ' ')
		i++;
	str->inf.t_path_we = ft_strdup(s + i);
	if (str->inf.t_path_we == NULL)
		ft_put_message("something wrong with no_path to texture");
}

void			ft_get_s_path(char *s, t_str *str)
{
	int			i;

	i = 0;
	str->chk.am_s++;
	if (str->chk.am_s != 1)
		ft_put_message("wrong amount of S teture");
	while (s[i] == ' ')
		i++;
	str->inf.t_path_s = ft_strdup(s + i);
	if (str->inf.t_path_s == NULL)
		ft_put_message("something wrong with no_path to texture");
}
