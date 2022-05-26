/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_inf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:17:37 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/24 15:52:42 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_gnl_inf(int fd, t_str *str, t_list **list)
{
	char	*p;
	int		r;
	int		i;

	r = 1;
	while (r > 0)
	{
		i = 0;
		r = get_next_line(fd, &p);
		if (r < 0)
			ft_put_message("reading error");
		while (p[i] == ' ')
			i++;
		if ((p[i] == '\0') && (*list == NULL))
		{
			free(p);
			continue;
		}
		if ((p[i] == '0') || (p[i] == '1') || (p[i] == '2') || (p[i] == '\0'))
		{
			ft_lstadd_back(list, ft_lstnew(p));
			continue;
		}
		ft_get_inf(p, str);
	}
}

void		ft_parser_inf(int fd, t_str *str)
{
	t_list	*list;

	list = NULL;
	ft_gnl_inf(fd, str, &list);
	ft_get_map(list, str);
	close(fd);
	ft_check_inf(str);
}
