/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:45:49 by thi-le            #+#    #+#             */
/*   Updated: 2023/02/17 12:00:14 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
long int	ft_atol(const char *str)
{
	long	res;
	long	i;
	long	sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10;
		res = res +(str[i] - '0');
		i++;
	}
	return (res * sign);
}
