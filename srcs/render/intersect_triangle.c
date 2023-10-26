/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:01:47 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:43:21 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathRT.h"
#include "miniRT.h"
#include "render.h"
#include "structs.h"

/*http://www.lighthouse3d.com/tutorials/maths/ray-triangle-intersection/*/
// https://fileadmin.cs.lth.se/cs/Personal/Tomas_Akenine-Moller/raytri/

bool	intersect_triangle(t_ray *ray, t_objs *triangle, t_intersect_list *xs)
{
	t_vector	h;
	t_vector	s;
	double		auvt[4];

	cross_product(&h, &ray->direction, &triangle->edge[2]);
	auvt[0] = dot_product(&triangle->edge[1], &h);
	if (auvt[0] > -EPSILON && auvt[0] < EPSILON)
		return (false);
	auvt[0] = 1 / auvt[0];
	sub_vec(&s, &ray->origin, &triangle->vertex[0]);
	auvt[1] = auvt[0] * dot_product(&s, &h);
	if (auvt[1] < 0 || auvt[1] > 1)
		return (false);
	cross_product(&h, &s, &triangle->edge[1]);
	auvt[2] = auvt[0] * dot_product(&ray->direction, &h);
	if (auvt[2] < 0 || auvt[1] + auvt[2] > 1)
		return (false);
	auvt[3] = auvt[0] * dot_product(&triangle->edge[2], &h);
	if (auvt[3] < EPSILON)
		return (false);
	xs->arr[xs->count].t = auvt[3];
	xs->arr[xs->count].obj = triangle;
	xs->count += 1;
	return (true);
}

// bool intersect_triangle(t_ray *ray, t_objs *triangle, t_intersect_list *xs)
// {
// 	t_vector	h;
// 	t_vector	s;
// 	double		auvt[0];
// 	double		auvt[1];
// 	double		auvt[2];
// 	double 		auvt[3];

// 	cross_product(&h, &triangle->vertex[1], &triangle->edge[2]);
// 	auvt[0] = dot_product(&triangle->edge[1], &h);
// 	if (auvt[0] > -EPSILON && auvt[0] < EPSILON)
// 		return (false); // ray is parallel to triangle
// 	auvt[0] = 1 / auvt[0];
// 	sub_vec(&s, &ray->origin, &triangle->vertex[0]);
// 	auvt[1] = auvt[0] * dot_product(&s, &h);
// 	if (auvt[1] < 0 || auvt[1] > 1)
// 		return (false);
// 	cross_product(&h, &s, &triangle->edge[1]);
// 	auvt[2] = auvt[0] * dot_product(&ray->direction, &h);
// 	if (auvt[2] < 0 || auvt[1] + auvt[2] > 1)
// 		return (false);
// 	// at this stage we can compute auvt[3] to find out where
// 	// the intersection point is on the line
// 	auvt[3] = auvt[0] * dot_product(&triangle->edge[2], &h);
// 	if (auvt[3] > EPSILON)
// 	{
// 		xs->arr[xs->count].auvt[3] = auvt[3];
// 		xs->arr[xs->count].obj = triangle;
// 		xs->count += 1;
// 		return (true);
// 	}
// 	else	// this means that there is auvt[0] line intersection
// 			// but not auvt[0] ray intersection
// 		return (false);
// }
