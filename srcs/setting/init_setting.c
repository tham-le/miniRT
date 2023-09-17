/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:38:12 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 21:09:06 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "setting.h"

void	init_setting(t_data *data)
{
	double	half_view;

	data->settings.hsize = W_WIDTH;
	data->settings.vsize = W_HEIGHT;
	data->settings.aspect_ratio =\
	(double)data->settings.hsize / (double)data->settings.vsize;
	half_view = tan(data->scene.camera.fov / 2);
	if (data->settings.aspect_ratio >= 1)
	{
		data->settings.half_width = half_view;
		data->settings.half_height = half_view / data->settings.aspect_ratio;
	}
	else
	{
		data->settings.half_width = half_view * data->settings.aspect_ratio;
		data->settings.half_height = half_view;
	}
	data->settings.pixel_size = (data->settings.half_width * 2) / \
	(double)data->settings.hsize;
}
