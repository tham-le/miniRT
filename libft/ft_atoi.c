/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itchinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:48 by itchinda          #+#    #+#             */
/*   Updated: 2023/08/16 16:24:49 by itchinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"


int	ft_isdigit(int c)
{
	return (47 < c && c < 58);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	s;

	s = 1;
	n = 0;
	i = 0;
	while (str[i] == 32 || (8 < str[i] && str[i] < 14))
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			s *= -1;
	while (ft_isdigit(str[i]))
		n = n * 10 + str[i++] - 48;
	return (n * s);
}
