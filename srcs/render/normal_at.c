/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:11:17 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:47:46 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	sphere_normal(t_vector *normal, const t_objs *obj,
				const t_vector *itx_point)
{
	t_vector	world_normal;

	mat_vec_multiply(normal, &obj->inv_transf, itx_point);
	normalize_vec(normal);
	normal->w = 0;
	mat_vec_multiply(&world_normal, &obj->norm_transf, normal);
	world_normal.w = 0;
	normalize_vec(&world_normal);
	return (world_normal);
}

t_vector	cylinder_normal(const t_objs *shape, const t_vector *itx_point)
{
	double		distance;
	t_vector	normal;
	t_vector	point;
	t_vector	world_normal;

	mat_vec_multiply(&point, &shape->inv_transf, itx_point);
	point.w = 0;
	distance = point.x * point.x + point.z * point.z;
	ft_bzero(&normal, sizeof(t_vector));
	if (distance < 1 && (point.y >= (shape->height / 2) - EPSILON))
		normal.y = 1;
	else if (distance < 1 && (point.y <= -(shape->height / 2) + EPSILON))
		normal.y = -1;
	else
	{
		normal.x = point.x;
		normal.z = point.z;
		normalize_vec(&normal);
	}
	mat_vec_multiply(&world_normal, &shape->norm_transf, &normal);
	world_normal.w = 0;
	normalize_vec(&world_normal);
	return (world_normal);
}

t_vector	cone_normal(const t_objs *shape, const t_vector *itx_point)
{
	double		distance;
	t_vector	normal;
	t_vector	point;
	t_vector	world_normal;

	mat_vec_multiply(&point, &shape->inv_transf, itx_point);
	distance = point.x * point.x + point.z * point.z;
	ft_bzero(&normal, sizeof(t_vector));
	if (distance < fabs(point.y) * fabs(point.y) && (point.y >= 0.5 - EPSILON))
		normal.y = 1;
	else if (distance < fabs(point.y) * fabs(point.y) && (point.y <= EPSILON))
		normal.y = -1;
	else
	{
		normal.y = sqrt(distance);
		if (point.y > 0)
			normal.y *= -1;
		normal = (t_vector){point.x, normal.y, point.z, 0};
		normalize_vec(&normal);
	}
	mat_vec_multiply(&world_normal, &shape->norm_transf, &normal);
	normalize_vec(&world_normal);
	return (world_normal);
}

t_vector	triangle_normal(const t_objs *shape, const t_vector *itx_point)
{
	t_vector	world_normal;

	(void)itx_point;
	mat_vec_multiply(&world_normal, &shape->norm_transf, &shape->normal);
	world_normal.w = 0;
	normalize_vec(&world_normal);
	return (shape->normal);
}

t_vector	normal_at(const t_objs *obj, const t_vector *itx_point)
{
	t_vector	normal;

	if (obj->type == SPHERE)
		return (sphere_normal(&normal, obj, itx_point));
	else if (obj->type == PLAN)
		return (obj->vector);
	else if (obj->type == CYLINDER)
		return (cylinder_normal(obj, itx_point));
	else if (obj->type == CONE)
		return (cone_normal(obj, itx_point));
	else if (obj->type == TRIANGLE)
		return (obj->normal);
	ft_bzero(&normal, sizeof(t_vector));
	return (normal);
}

	// if (obj->normal != NULL)
	// 	return (normal_map(normal, obj, itx_point));
