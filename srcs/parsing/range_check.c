/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:05:10 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/27 19:40:22 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_ratio(char *flt, t_data *data)
{
	float	converted_num;

	if (check_float(flt))
		return (printf(ERROR_RATIO, data->nb_lines), 1);
	converted_num = ft_atod(flt);
	if (converted_num < 0 || converted_num > 1)
	{
		printf(ERROR_RATIO_RANGE, data->nb_lines);
		return (1);
	}
	return (0);
}

int	check_vector(char *vect, t_data *data)
{
	char	**position;
	int		vec_x;
	int		vec_y;
	int		vec_z;

	if (check_position(vect, data))
		return (1);
	position = ft_split(vect, ',');
	if (!position)
		return (1);
	vec_x = ft_atod(position[0]);
	vec_y = ft_atod(position[1]);
	vec_z = ft_atod(position[2]);
	ft_freearr(position);
	if (vec_x < -1 || vec_x > 1 || vec_y < -1
		|| vec_y > 1 || vec_z < -1 || vec_z > 1)
		return (1);
	return (0);
}

int	check_fov(char *fov)
{
	int	converted;

	converted = ft_atoi(fov);
	if (only_digits(fov))
		return (1);
	if (converted < 0 || converted > 180)
		return (1);
	return (0);
}
