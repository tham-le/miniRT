/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:17:34 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:47:30 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "render.h"
#include "structs.h"

static bool	within_cone_radius(const t_ray *ray, double t, double cone_val)
{
	double	x;
	double	z;

	x = ray->origin.x + ray->direction.x * t;
	z = ray->origin.z + ray->direction.z * t;
	if ((x * x + z * z) <= (cone_val * cone_val))
		return (true);
	return (false);
}

static bool	check_cone_caps(const t_ray *ray, t_objs *shape,
		t_intersect_list *xs)
{
	bool	intersected;
	double	t;

	intersected = false;
	if (fabs(ray->direction.y) > EPSILON)
	{
		t = ((1.0 / 2) - ray->origin.y) / ray->direction.y;
		if (within_cone_radius(ray, t, 1.0 / 2))
		{
			xs->arr[xs->count].t = t;
			xs->arr[xs->count].obj = shape;
			xs->count++;
			intersected = true;
		}
		t = -ray->origin.y / ray->direction.y;
		if (within_cone_radius(ray, t, 0))
		{
			xs->arr[xs->count].t = t;
			xs->arr[xs->count].obj = shape;
			xs->count++;
			intersected = true;
		}
	}
	return (intersected);
}

static bool	add_cone_intersections(t_objs *shape, const t_ray *ray,
	t_intersect_list *xs, double *ts)
{
	double	y0;
	double	y1;
	bool	intersected;

	intersected = false;
	if (ts[0] > ts[1])
		ft_swapd(&ts[0], &ts[1]);
	y0 = ray->origin.y + ts[0] * ray->direction.y;
	if (y0 > 0 && y0 < ((1.0 / 2)))
	{
		xs->arr[xs->count].t = ts[0];
		xs->arr[xs->count].obj = shape;
		xs->count++;
		intersected = true;
	}
	y1 = ray->origin.y + ts[1] * ray->direction.y;
	if (y1 > 0 && y1 < ((1.0 / 2)))
	{
		xs->arr[xs->count].t = ts[1];
		xs->arr[xs->count].obj = shape;
		xs->count++;
		intersected = true;
	}
	return (intersected);
}

static double	get_cone_discriminant(const t_ray *ray, double *abc)
{
	double	discriminant;

	abc[0] = ray->direction.x * ray->direction.x \
			- ray->direction.y * ray->direction.y \
			+ ray->direction.z * ray->direction.z;
	abc[1] = 2 * ray->direction.x * ray->origin.x \
			- 2 * ray->direction.y * ray->origin.y \
			+ 2 * ray->direction.z * ray->origin.z;
	abc[2] = ray->origin.x * ray->origin.x \
			- ray->origin.y * ray->origin.y \
			+ ray->origin.z * ray->origin.z;
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	return (discriminant);
}

bool	intersect_cone(const t_ray *ray, t_objs *shape, t_intersect_list *xs)
{
	bool	intersected;
	double	abc[3];
	double	discriminant;
	double	ts[2];

	intersected = check_cone_caps(ray, shape, xs);
	discriminant = get_cone_discriminant(ray, abc);
	if (discriminant < 0)
		return (intersected);
	if (fabs(abc[0]) < 0.000001 && fabs(abc[1]) > 0.1)
	{
		xs->arr[xs->count].t = -abc[2] / (2 * abc[1]);
		xs->arr[xs->count++].obj = shape;
		return (intersected);
	}
	discriminant = sqrt(discriminant);
	abc[0] *= 2;
	abc[1] *= -1;
	ts[0] = (abc[1] - discriminant) / (abc[0]);
	ts[1] = (abc[1] + discriminant) / (abc[0]);
	if (add_cone_intersections(shape, ray, xs, ts) == true)
		intersected = true;
	return (intersected);
}
