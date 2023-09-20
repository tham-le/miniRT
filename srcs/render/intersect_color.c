/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:44:50 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 21:26:23 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	intersect_world(t_data	*data, t_ray *ray)
{
	t_objs	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->type == SPHERE)
			intersect_sphere(data, ray, obj);
		else if (obj->type == PLANE)
			intersect_plane(ray, obj);
		else if (obj->type == CYLINDER)
			intersect_cylinder(ray, obj);
		// else if (obj->type == SQUARE)
		// 	intersect_square(data, ray, obj);
		// else if (obj->type == TRIANGLE)
		// 	intersect_triangle(data, ray, obj);
		obj = obj->next;
	}
}


t_color intersect_color(t_data *data, t_ray *ray)
{
	t_color color;

	intersect_world(data, ray);
	if (ray->hit)
		color = ray->color;
	else
		color = data->scene.ambient.color;
	return (color);
}