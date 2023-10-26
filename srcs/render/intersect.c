/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:04:48 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:13:32 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	transform_ray(t_ray *transformed_ray, const t_ray *ray,
	const t_objs *obj)
{
	mat_vec_multiply(&transformed_ray->origin, &obj->inv_transf,
		&ray->origin);
	mat_vec_multiply(&transformed_ray->direction, &obj->inv_transf,
		&ray->direction);
}

void	intersect(t_ray	*ray, t_objs *obj, t_intersect_list *arr)
{
	t_ray	transformed_ray;

	if (arr->count >= MAX_INTERSECT)
		return ;
	if (obj->type == SPHERE)
		intersect_sphere(ray, arr, obj);
	if (obj->type == PLAN)
		intersect_plane(ray, obj, arr);
	if (obj->type == TRIANGLE)
		intersect_triangle(ray, obj, arr);
	transform_ray(&transformed_ray, ray, obj);
	if (obj->type == CYLINDER)
		intersect_cylinder(&transformed_ray, obj, arr);
	if (obj->type == CONE)
		intersect_cone(&transformed_ray, obj, arr);
}
