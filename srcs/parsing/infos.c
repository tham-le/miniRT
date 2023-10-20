/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itchinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:15:02 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/19 22:31:26 by itchinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_position(char *elems, t_data *data)
{
	char	**position;

	position = ft_split(elems, ',');
	if (!position || ft_tabsize(position) != 3)
		return (printf(ERROR_POS_ARGS, data->nb_lines), 1);
	if (check_float(position[0]) || check_float(position[1])
		|| check_float(position[2]))
		return (printf(ERROR_POS_ARGS_DIGIT, data->nb_lines), ft_freearr(position), 1);
	ft_freearr(position);
	return (0);
}

t_vector	get_position(char *elems)
{
	char		**position;
	t_vector	vec_pos;

	position = ft_split(elems, ',');
	vec_pos.x = ft_atod(position[0]);
	vec_pos.y = ft_atod(position[1]);
	vec_pos.z = ft_atod(position[2]);
	vec_pos.w = 1;
	ft_freearr(position);
	return (vec_pos);
}

int	check_color(char *elems, t_data *data)
{
	char		**color;
	int			col_r;
	int			col_g;
	int			col_b;

	color = ft_split(elems, ',');
	if (!color || ft_tabsize(color) != 3)
		return (printf(ERROR_COL_ARGS, data->nb_lines), 1);
	col_r = ft_atod(color[0]);
	col_g = ft_atod(color[1]);
	col_b = ft_atod(color[2]);
	if (only_digits(color[0]) || only_digits(color[1]) || only_digits(color[2]))
		return (ft_freearr(color), printf(ERROR_COL_ARGS_DIGIT, data->nb_lines), 1);
	if (col_r < 0 || col_r > 255 || col_g < 0
		|| col_g > 255 || col_b < 0 || col_b > 255)
		return (ft_freearr(color), printf(ERROR_COL_ARGS_RANGE, data->nb_lines), 1);
	ft_freearr(color);
	return (0);
}

t_color	get_color(char *elems)
{
	char	**color;
	t_color	vec_col;

	color = ft_split(elems, ',');
	vec_col.r = ft_atod(color[0]) / 255.f;
	vec_col.g = ft_atod(color[1]) / 255.f;
	vec_col.b = ft_atod(color[2]) / 255.f;
	ft_freearr(color);
	return (vec_col);
}
