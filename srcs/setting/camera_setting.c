/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:35:38 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:23:00 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	camera_setting(t_data *data)
{
	double	half_view;
	double	h;
	double	w;

	h = data->height;
	w = data->width;
	half_view = tan((data->scene.camera.fov / 2.0f));
	data->scene.camera.aspect = w / h;
	if (data->scene.camera.aspect >= 1)
	{
		data->scene.camera.half_width = half_view;
		data->scene.camera.half_height = half_view / data->scene.camera.aspect;
	}
	else
	{
		data->scene.camera.half_width = half_view * data->scene.camera.aspect;
		data->scene.camera.half_height = half_view;
	}
	data->scene.camera.pixel_size = (data->scene.camera.half_width * 2) / w;
	data->scene.camera.phi = acos(data->scene.camera.vector.y);
	data->scene.camera.theta = atan(data->scene.camera.vector.z \
		/ data->scene.camera.vector.x);
}
