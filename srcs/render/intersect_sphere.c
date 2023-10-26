/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:49:21 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:48:06 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"
#include <stdio.h>

bool	intersect_sphere(t_ray *ray, t_intersect_list *xs, \
t_objs *sphere)
{
	t_vector	l;
	double		b;
	double		t1c;
	double		d2;

	sub_vec(&l, &sphere->position, &ray->origin);
	b = dot_product(&l, &ray->direction);
	if (b < 0)
		return (false);
	d2 = dot_product(&l, &l) - b * b;
	if (d2 > sphere->squared_radius)
		return (false);
	t1c = sqrt(sphere->squared_radius - d2);
	xs->arr[xs->count].obj = sphere;
	xs->arr[xs->count].t = b + t1c;
	xs->arr[xs->count].obj = sphere;
	xs->arr[xs->count + 1].t = b - t1c;
	xs->arr[xs->count + 1].obj = sphere;
	xs->count += 2;
	return (false);
}

bool	intersect_plane(const t_ray *ray, t_objs *plane,
		t_intersect_list *xs)
{
	double	denom;
	double	t;

	denom = dot_product(&ray->direction, &plane->vector);
	if (fabs(denom) < EPSILON)
		return (false);
	t = -(dot_product(&ray->origin, &plane->vector) \
		- plane->distance_to_origin) / denom;
	if (t < 0)
		return (false);
	xs->arr[xs->count].t = t;
	xs->arr[xs->count].obj = plane;
	xs->count++;
	return (true);
}
/*bool	intersect_sphere(t_ray *ray, t_intersect_list *xs,
t_objs *sphere)
{
	t_vector	l;
	double		a;
	double		b;
	double		c;
	double		delta;

	sub_vec(&l, &ray->origin, &sphere->position);
	a = dot_product(&ray->direction, &ray->direction);
	b = 2 * dot_product(&l, &ray->direction);
	c = dot_product(&l, &l) - sphere->squared_radius;
	delta = b * b - 4 * a * c;
	if (delta <= EPSILON)
		return (false);
	delta = sqrt(delta);
	xs->arr[xs->count].t = (-b - delta) / (2 * a);
	xs->arr[xs->count].obj = sphere;
	xs->arr[xs->count + 1].t = (-b + delta) / (2 * a);
	xs->arr[xs->count + 1].obj = sphere;
	xs->count += 2;
	return (true);
}*/
/*Sphere intersection that does not need ray to be transformed*/
/*bool	intersect_sphere(t_ray *ray, t_intersect_list *xs,\
t_objs *sphere)
{
	t_vector	l;
	double		b;
	double		c;
	double		h;

	sub_vec(&l, &ray->origin, &sphere->position);
	b = dot_product(&l, &ray->direction);
	c = dot_product(&l, &l) - sphere->squared_radius;
	h = b * b - c;
	if (h <= EPSILON)
		return (false);
	h = sqrt(h);
	xs->arr[xs->count].t = -b - h;
	xs->arr[xs->count].obj = sphere;
	xs->arr[xs->count + 1].t = -b + h;
	xs->arr[xs->count + 1].obj = sphere;
	xs->count += 2;
	return (true);
}*/
