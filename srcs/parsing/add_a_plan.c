/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_a_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:38:25 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:42:28 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	add_options(obj, elems);
	obj->type = PLAN;
	obj->position = get_position(elems[1]);
	obj->vector = get_position(elems[2]);
	normalize_vec(&obj->vector);
	obj->color = get_color(elems[3]);
	obj->distance_to_origin = dot_product(&obj->vector, &obj->position);
	push_object(obj, &data->objs);
	return (0);
}
