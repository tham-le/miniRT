/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:30:08 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 17:40:46 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"

void	ray_to_pixel(t_camera *camera, t_ray *ray, double x, double y)
{
	double		world_x;
	double		world_y;
	t_vector	pixel;
	t_vector	world_point;
	t_vector	center;

	world_x = camera->half_width - (x) * camera->pixel_size;
	world_y = camera->half_height - (y) * camera->pixel_size;
	world_point.x = world_x;
	world_point.y = world_y;
	world_point.z = -1;
	world_point.w = 1;
	mat_vec_multiply(&pixel, &camera->inverse, &world_point);
	ft_bzero(&center, sizeof(t_vector));
	center.w = 1;
	mat_vec_multiply(&ray->origin, &camera->inverse, &center);
	sub_vec(&ray->direction, &pixel, &ray->origin);
	ray->direction.w = 0;
	fast_normalize_vec(&ray->direction);
}
