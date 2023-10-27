/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_a_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:37:41 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 22:52:58 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	err_cyl(char **elems, t_data *data)
{
	if (ft_tabsize(elems) < 6)
		return (printf("Error: line %d: \
you should enter at least 5 infos for each cylindre\n", \
			data->nb_lines), 1);
	if (check_position(elems[1], data) || check_vector(elems[2], data) \
		|| check_color(elems[5], data))
		return (1);
	if (check_float(elems[3]) || check_float(elems[3]))
		return (printf("Error: line %d: \
the height/diameter arguments of a cylinder contains a character \
that is not a digit\n", data->nb_lines), 1);
	return (0);
}

int	add_a_cylindre(t_data *data, char **elems)
{
	t_objs	*obj;

	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (err_cyl(elems, data))
		return (free(obj), 1);
	if (add_options(obj, elems, 6) == false)
		return (free(obj), 1);
	obj->type = CYLINDER;
	obj->position = get_position(elems[1]);
	obj->vector = get_position(elems[2]);
	obj->diametre = ft_atod(elems[3]);
	if (obj->diametre < 0)
		obj->diametre = 0;
	obj->radius = obj->diametre / 2;
	obj->height = ft_atod(elems[4]);
	obj->color = get_color(elems[5]);
	push_object(obj, &data->objs);
	return (0);
}
