/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:55:54 by bchelste          #+#    #+#             */
/*   Updated: 2021/03/23 20:43:05 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3d.h"

int		ft_atoi_cub(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((*str == '\n') || (*str == '\t') || (*str == '\v') ||
		(*str == '\r') || (*str == '\f') || (*str == ' '))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		res = (res * 10) + (*str - 48);
		str++;
		i++;
		if (i >= 5)
			return (50000 * sign);
	}
	return (res * sign);
}
