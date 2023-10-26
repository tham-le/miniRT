/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:59:08 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 22:14:29 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cone_map(double *u, double *v, t_vector *point)
{
	double	theta;

	theta = atan2(point->x, point->z);
	*u = (1 - (theta / (2 * M_PI) + 0.5)) / 2;
	*v = (point->y - floor(point->y)) / 2;
}

void	cylinder_map(double *u, double *v, t_vector *point)
{
	double	theta;

	theta = atan2(point->x, point->z);
	*u = (1 - (theta / (2 * M_PI) + 0.5));
	*v = (point->y - floor(point->y));
}

void	plan_map(double *u, double *v, t_vector *point)
{
	*v = fmod(point->z, 1) / 10;
	if (*v < 0)
		*v += 1;
	*u = fmod(point->x, 1) / 10;
}

void	sphere_map(double *u, double *v, t_vector *point)
{
	double		theta;
	t_vector	vec;
	double		radius;
	double		phi;

	vec = (t_vector){point->x, point->y, point->z, 0};
	theta = atan2(point->x, point->z);
	radius = vec_magnitude(&vec);
	phi = asin(point->y / radius);
	*u = 0.5 + theta / (2 * M_PI);
	*v = 0.5 + (phi / M_PI);
}
