/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:49:21 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 22:08:15 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	intersect_sphere(t_data *data, t_ray *ray, t_objs *ob)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		t;

	(void)data;
	oc = vec_minus(&ray->origin, &ob->position);
	a = vec_dot(&ray->direction, &ray->direction);
	b = 2.0 * vec_dot(&oc, &ray->direction);
	c = vec_dot(&oc, &oc) - ob->diametre * ob->diametre;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	t = (-b - sqrt(discriminant)) / (2.0 * a);
	if (t < 0)
		return ;
	ray->t = t;
	ray->hit = 1;
	ray->color = ob->color;
}
