/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itchinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:31:53 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/19 21:32:45 by itchinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_scene(t_data *data)
{
	init_sc_ambient(data->scene.ambient);
	init_sc_light(*data->scene.light);
	init_sc_camera(data->scene.camera);
}

void	init_sc_camera(t_camera camera)
{
	camera.fov = 0;
	camera.position.x = 0;
	camera.position.y = 0;
	camera.position.z = 0;
	camera.vector.x = 0;
	camera.vector.y = 0;
	camera.vector.z = 0;
}

void	init_sc_light(t_light light)
{
	light.color.r = 0;
	light.color.g = 0;
	light.color.b = 0;
	light.position.x = 0;
	light.position.y = 0;
	light.position.z = 0;
	light.ratio = 0;
}

void	init_sc_ambient(t_ambient ambient)
{
	ambient.color.r = 0;
	ambient.color.g = 0;
	ambient.color.b = 0;
	ambient.ratio = 0;
}
