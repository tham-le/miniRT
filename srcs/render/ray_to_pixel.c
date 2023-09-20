/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:30:08 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 22:02:25 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	ray_to_pixel(t_data *data, int x, int y)
{
	t_ray	ray;

	ray.direction.x = (2 * ((x + 0.5) / data->settings.vsize) - 1) \
		* data->settings.aspect_ratio * data->scene.camera.fov;
	ray.direction.y = (1 - 2 * ((y + 0.5) / data->settings.hsize))
		* data->scene.camera.fov;
	ray.direction.z = -1;
	ray.direction = vec_norm(ray.direction);
	ray.origin = data->scene.camera.position;
	return (ray);
}
