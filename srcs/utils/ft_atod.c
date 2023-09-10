/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:41:05 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/09 18:57:28 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_bool	ft_iswhite(char c)
{
	if (c == '\n' || c == ' ' || c == '\f' || c == '\t' || c == '\v'
		|| c == '\r')
		return (true);
	return (false);
}

double			ft_atod(const char *str)
{
	double			nb;
	double			part;
	double			sign;

	while (ft_iswhite(*str))
		str++;
	sign = (*str == '-') ? -1.0 : 1.0;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
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
