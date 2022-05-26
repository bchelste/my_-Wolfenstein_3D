/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:44:54 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/15 00:23:16 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

static void		ft_free(void **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

static int		ft_r_line(char **rem, int r, char **line)
{
	char		*p;
	size_t		n;

	if ((r == 0) && ((ft_strchr(*rem, '\n')) == NULL))
	{
		*line = ft_strdup(*rem);
		ft_free((void **)rem);
		return (0);
	}
	if (r > 0)
	{
		n = ft_strlen(*rem) - ft_strlen(ft_strchr(*rem, '\n'));
		*line = ft_substr(*rem, 0, n);
		p = ft_strdup(*rem + (ft_strlen(*line) + 1));
		ft_free((void **)rem);
		*rem = p;
		return (1);
	}
	ft_free((void **)rem);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	char		*p;
	static char	*rem;
	int			r;

	r = 1;
	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE < 1))
		return (-1);
	if ((!(rem)) && (!(rem = ft_strdup(""))))
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ft_strchr(rem, '\n') == NULL) && (r = read(fd, buf, BUFFER_SIZE)))
	{
		buf[r] = '\0';
		if (!(p = ft_strjoin(rem, buf)))
		{
			ft_free((void **)&rem);
			return (-1);
		}
		ft_free((void **)&rem);
		rem = p;
	}
	free(buf);
	return (ft_r_line(&rem, r, line));
}
