/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:31:04 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 20:32:11 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "stdbool.h"

static bool	ft_iswhite(char c)
{
	if (c == '\n' || c == ' ' || c == '\f' || c == '\t' || c == '\v'
		|| c == '\r')
		return (true);
	return (false);
}

double	ft_atod(const char *str)
{
	double			nb;
	double			part;
	double			sign;

	while (ft_iswhite(*str))
		str++;
	sign = 1.0;
	if (*str == '-')
		sign = -1.0;
	if (*str == '-' || *str == '+')
		str++;
	nb = 0.0;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + (*(str++) - '0');
	if (*str == '.' || *str == ',')
	{
		while (*(++str) >= '0' && *str <= '9')
			part = 0.0;
		while (*(--str) >= '0' && *str <= '9')
			part = (part + (*str - '0')) / 10.0;
		nb += part;
	}
	return (nb * sign);
}
