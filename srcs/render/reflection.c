/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:07:18 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 17:40:45 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "render.h"
#include "structs.h"

t_color	cast_reflection_ray(t_data	*data, t_intersect *intersection,
			int reflection_depth, t_light	*light);

t_color	reflection_color(t_intersect *itx, t_data *data, \
		int remaining, t_light *light)
{
	t_color			final_color;
	t_color			light_color;
	t_color			reflected;

	ft_bzero(&final_color, sizeof(t_color));
	light_color = shading(itx, data, light);
	reflected = cast_reflection_ray(data, itx, remaining - 1, light);
	add_colors(&final_color, &final_color, &light_color);
	add_colors(&final_color, &final_color, &reflected);
	return (final_color);
}

static void	intersect_obj(t_data *data, t_ray *ray, t_intersect_list *arr)
{
	t_objs	*obj;

	obj = data->objs;
	while (obj)
	{
		intersect(ray, obj, arr);
		obj = obj->next;
	}
}

t_color	cast_reflection_ray(t_data	*data, t_intersect *intersection,
		int reflection_depth, t_light	*light)
{
	t_ray				ray;
	t_intersect_list	arr;
	t_color				reflected;
	t_intersect			*itx;

	if (intersection->obj->reflective == 0 || reflection_depth == 0)
		return ((t_color){0, 0, 0});
	ft_bzero(&reflected, sizeof(t_color));
	ray.origin = intersection->over_point;
	ray.direction = intersection->reflect;
	arr.count = 0;
	intersect_obj(data, &ray, &arr);
	itx = hit(&arr);
	if (itx != NULL)
	{
		pre_computations(itx, &ray);
		reflected = reflection_color(itx, data, reflection_depth, light);
	}
	mult_color(&reflected, &reflected, intersection->obj->reflective);
	return (reflected);
}
