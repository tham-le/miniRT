/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:01:47 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/14 18:41:36 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathRT.h"
#include "miniRT.h"
#include "render.h"
#include "structs.h"

/*http://www.lighthouse3d.com/tutorials/maths/ray-triangle-intersection/*/
// https://fileadmin.cs.lth.se/cs/Personal/Tomas_Akenine-Moller/raytri/

bool intersect_triangle(t_ray *ray, t_objs *triangle, t_intersect_list *xs)
{
	t_vector	h;
	t_vector	s;
	double		a;
	double		u;
	double		v;
	double 		t;

	cross_product(&h, &ray->direction, &triangle->edge[2]);
	a = dot_product(&triangle->edge[1], &h);
	if (a > -EPSILON && a < EPSILON)
		return (false); // ray is parallel to triangle
	a = 1 / a;
	sub_vec(&s, &ray->origin, &triangle->vertex[0]);
	u = a * dot_product(&s, &h);
	if (u < 0 || u > 1)
		return (false);
	cross_product(&h, &s, &triangle->edge[1]);
	v = a * dot_product(&ray->direction, &h);
	if (v < 0 || u + v > 1)
		return (false);
	// at this stage we can compute t to find out where
	// the intersection point is on the line
	t = a * dot_product(&triangle->edge[2], &h);
	if (t > EPSILON)
	{
		xs->arr[xs->count].t = t;
		xs->arr[xs->count].obj = triangle;
		xs->count += 1;
		return (true);
	}
	else	// this means that there is a line intersection
			// but not a ray intersection
		return (false);
}

// bool intersect_triangle(t_ray *ray, t_objs *triangle, t_intersect_list *xs)
// {
// 	t_vector	h;
// 	t_vector	s;
// 	double		a;
// 	double		u;
// 	double		v;
// 	double 		t;

// 	cross_product(&h, &triangle->vertex[1], &triangle->edge[2]);
// 	a = dot_product(&triangle->edge[1], &h);
// 	if (a > -EPSILON && a < EPSILON)
// 		return (false); // ray is parallel to triangle
// 	a = 1 / a;
// 	sub_vec(&s, &ray->origin, &triangle->vertex[0]);
// 	u = a * dot_product(&s, &h);
// 	if (u < 0 || u > 1)
// 		return (false);
// 	cross_product(&h, &s, &triangle->edge[1]);
// 	v = a * dot_product(&ray->direction, &h);
// 	if (v < 0 || u + v > 1)
// 		return (false);
// 	// at this stage we can compute t to find out where
// 	// the intersection point is on the line
// 	t = a * dot_product(&triangle->edge[2], &h);
// 	if (t > EPSILON)
// 	{
// 		xs->arr[xs->count].t = t;
// 		xs->arr[xs->count].obj = triangle;
// 		xs->count += 1;
// 		return (true);
// 	}
// 	else	// this means that there is a line intersection
// 			// but not a ray intersection
// 		return (false);
// }
