/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_a_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:38:25 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 23:00:14 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_normal_plan(t_objs *obj, int nb_lines)
{
	if (obj->vector.x == 0 && obj->vector.y == 0 && obj->vector.z == 0)
	{
		printf("Error: line %d: the normal vector of the plan \
cannot be null or negative\n", nb_lines);
		return (1);
	}
	normalize_vec(&obj->vector);
	return (0);
}

int	add_a_plan(t_data *data, char	**elems)
{
	t_objs	*obj;

	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (ft_tabsize(elems) < 4)
		return (free(obj), printf("Error: line %d: \
you should enter at least 5 infos for each plan\n", \
			data->nb_lines), 1);
	if (check_position(elems[1], data) || check_vector(elems[2], data) \
		|| check_color(elems[3], data))
		return (free(obj), 1);
	if (add_options(obj, elems, 4) == false)
	{
		printf("Error: line %d: wrong options\n", data->nb_lines);
		return (free(obj), 1);
	}
	obj->type = PLAN;
	obj->position = get_position(elems[1]);
	obj->vector = get_position(elems[2]);
	if (check_normal_plan(obj, data->nb_lines) == 1)
		return (free(obj), 1);
	obj->color = get_color(elems[3]);
	obj->distance_to_origin = dot_product(&obj->vector, &obj->position);
	push_object(obj, &data->objs);
	return (0);
}
