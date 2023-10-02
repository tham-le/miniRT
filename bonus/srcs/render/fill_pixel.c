/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:44:50 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/21 16:21:09 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	intersect_world(t_data	*data, t_ray *ray, t_intersect_list *arr)
{
	t_objs	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->type == SPHERE)
			return(intersect_sphere(ray, arr, obj));
		// else if (obj->type == PLANE)
		// 	intersect_plane(data, ray, obj);
		// else if (obj->type == SQUARE)
		// 	intersect_square(data, ray, obj);
		// else if (obj->type == CYLINDER)
		// 	intersect_cylinder(data, ray, obj);
		// else if (obj->type == TRIANGLE)
		// 	intersect_triangle(data, ray, obj);
		obj = obj->next;
	}
	return (false);
}


// t_color fill_pixel(t_data *data, t_ray *ray, t_intersect_list *arr)
// {
// 	t_color color;

// 	arr->count = 0;
// 	if (intersect_world(data, ray, arr) == true)
// 		color = ray->color;
// 	else
// 		color = (t_color){data->scene.ambient.color.r * ray->direction.x, data->scene.ambient.color.g, data->scene.ambient.color.b};
// 	return (color);
// }
