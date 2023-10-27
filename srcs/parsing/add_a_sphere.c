/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_a_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:35:39 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 17:37:57 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	err_sphere(char	**elems, t_objs **obj, t_data *data)
{
	if (ft_tabsize(elems) < 4)
		return (free(obj), printf("Error: line %d: \
			you should enter at least 5 infos for each sphere\n", \
			data->nb_lines), 1);
	if (check_position(elems[1], data) || check_color(elems[3], data))
		return (free(obj), 1);
	if (check_float(elems[2]))
		return (free(obj), printf("Error: line %d: \
			the diameter argument of a sphere contains a character that \
			is not a digit\n", data->nb_lines), 1);
	return (0);
}

int	add_a_sphere(t_data *data, char	**elems)
{
	t_objs	*obj;

	obj = ft_calloc(sizeof(t_objs), 1);
	if (!obj)
		return (write(STDERR_FILENO, ERR_MALLOC, 13), 1);
	init_obj_value(obj);
	if (err_sphere(elems, &obj, data))
		return (1);
	add_options(obj, elems);
	obj->type = SPHERE;
	obj->position = get_position(elems[1]);
	obj->diametre = ft_atod(elems[2]);
	if (obj->diametre < 0)
		return (free(obj), write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
	obj->radius = obj->diametre / 2;
	obj->squared_radius = obj->radius * obj->radius;
	obj->color = get_color(elems[3]);
	push_object(obj, &data->objs);
	return (0);
}
