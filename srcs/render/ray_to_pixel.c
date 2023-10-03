/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:30:08 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/29 18:00:31 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ray_to_pixel(t_data *data, t_ray *ray, double x, double y)
{
	double		world_x;
	double		world_y;
	t_vector	pixel;
	t_vector	world_point;
	t_vector	center;

	world_x = data->scene.camera.half_width - (x) * data->scene.camera.pixel_size;
	world_y = data->scene.camera.half_height - (y) * data->scene.camera.pixel_size;
	world_point.x = world_x;
	world_point.y = world_y;
	world_point.z = -1;
	world_point.w = 1;
	mat_vec_multiply(&pixel, &data->scene.camera.inverse, &world_point);
	ft_bzero(&center, sizeof(t_vector));
	center.w = 1;
	mat_vec_multiply(&ray->origin, &data->scene.camera.inverse, &center);
	sub_vec(&ray->direction, &pixel, &ray->origin);
	ray->direction.w = 0;
	normalize_vec(&ray->direction);
}
