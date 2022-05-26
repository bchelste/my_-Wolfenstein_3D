/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ff_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:49:56 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 03:08:38 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		**ft_create_array(int y, int x)
{
	char		**p;
	int			i;
	int			j;

	i = 0;
	p = (char**)malloc(sizeof(char*) * (y + 1));
	if (p == NULL)
		ft_put_message("malloc error");
	p[y] = NULL;
	while (i < y)
	{
		j = 0;
		p[i] = (char*)malloc(sizeof(char) * (x + 1));
		if (p[i] == NULL)
			ft_put_message("malloc error");
		p[i][x] = '\0';
		while (j < x)
			p[i][j++] = '0';
		i++;
	}
	return (p);
}

static t_pnt	*ft_add_pos(int i, int j)
{
	t_pnt		*arr;

	arr = (t_pnt*)malloc(sizeof(t_pnt));
	arr->p_x = j;
	arr->p_y = i;
	return (arr);
}

static void		ft_lst_add_dir(t_list **lst, int i, int j)
{
	ft_lstadd_front(lst, ft_lstnew(ft_add_pos((i + 1), j)));
	ft_lstadd_front(lst, ft_lstnew(ft_add_pos((i - 1), j)));
	ft_lstadd_front(lst, ft_lstnew(ft_add_pos(i, (j + 1))));
	ft_lstadd_front(lst, ft_lstnew(ft_add_pos(i, (j - 1))));
}

void			ft_check_ff_map(t_str *str)
{
	int			i;
	int			j;
	t_list		*lst;
	t_list		*tmp;

	i = str->inf.st_y;
	j = str->inf.st_x;
	lst = ft_lstnew(ft_add_pos(i, j));
	str->chk.ff_ar = ft_create_array(str->inf.map_h, str->inf.map_w);
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		i = ((t_pnt*)(tmp->content))->p_y;
		j = ((t_pnt*)(tmp->content))->p_x;
		ft_lstdelone(tmp, &free);
		if (((i >= str->inf.map_h) || (i < 0) ||
		(j >= str->inf.ar_mw[i]) || (j < 0)) || (str->inf.map[i][j] == ' '))
			ft_put_message("The file *.cub is not valid");
		if ((str->inf.map[i][j] == '1') || (str->chk.ff_ar[i][j] == '1'))
			continue ;
		str->chk.ff_ar[i][j] = '1';
		ft_lst_add_dir(&lst, i, j);
	}
}
