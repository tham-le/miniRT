/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_a_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:39:04 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 22:53:23 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	err_tri(char	**elems, t_objs **obj, t_data *data)
{	
	if (ft_tabsize(elems) < 5)
		return (free(obj), printf("Error: line %d: \
you should enter at least 5 infos for each triangle\n", \
			data->nb_lines), 1);
	if (check_position(elems[1], data) || check_position(elems[2], data) \
		|| check_position(elems[3], data) || check_color(elems[4], data))
		return (free(obj), 1);
	return (0);
}

int	add_a_triangle(t_data *data, char	**elems)
{
	t_objs	*obj;

	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (err_tri(elems, &obj, data))
		return (1);
	if (add_options(obj, elems, 5) == false)
		return (1);
	obj->type = TRIANGLE;
	obj->vertex[0] = get_position(elems[1]);
	obj->vertex[1] = get_position(elems[2]);
	obj->vertex[2] = get_position(elems[3]);
	sub_vec(&obj->edge[1], &obj->vertex[1], &obj->vertex[0]);
	sub_vec(&obj->edge[2], &obj->vertex[2], &obj->vertex[0]);
	cross_product(&obj->normal, &obj->edge[1], &obj->edge[2]);
	normalize_vec(&obj->normal);
	obj->normal.w = 0;
	obj->color = get_color(elems[4]);
	push_object(obj, &data->objs);
	return (0);
}
