/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:39:47 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/27 21:10:06 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathRT.h"
#include "miniRT.h"

int	add_ambient(t_data *data, char **elems)
{
	t_ambient		ambient;

	ft_bzero(&ambient, sizeof(t_ambient));
	if (data->scene.nb_amb > 1)
		return (printf(ERR_NB_AMBIENT, data->nb_lines), 1);
	if (ft_tabsize(elems) != 3 || is_void(elems[2][0]))
		return (printf(ERROR_NB_ARGS_AMB, data->nb_lines), 1);
	if (check_ratio(elems[1], data) || check_color(elems[2], data))
		return (1);
	data->scene.nb_amb++;
	ambient.ratio = ft_atod(elems[1]);
	ambient.color = get_color(elems[2]);
	data->scene.ambient = ambient;
	return (0);
}

int	add_light(t_data *data, char **elems)
{
	t_light		*light2;

	light2 = ft_calloc(sizeof(t_light), 1);
	if (!light2)
		return (1);
	if (ft_tabsize(elems) < 4)
		return (free(light2), printf(ERROR_NB_ARGS_LIGHT, data->nb_lines), 1);
	if (check_position(elems[1], data) || check_ratio(elems[2], data)
		|| check_color(elems[3], data))
		return (free(light2), 1);
	data->scene.nb_light++;
	light2->position = get_position(elems[1]);
	light2->ratio = ft_atod(elems[2]);
	light2->color = get_color(elems[3]);
	identity_matrix(&light2->added_rots);
	push_light(light2, &data->scene.light);
	return (0);
}

int	add_camera(t_data *data, char **elems)
{
	t_camera		camera;

	ft_bzero(&camera, sizeof(t_camera));
	data->scene.nb_cam++;
	if (data->scene.nb_cam != 1)
		return (printf(ERR_NB_CAMERA, data->nb_lines), 1);
	if (ft_tabsize(elems) < 4)
		return (printf(ERROR_NB_ARGS_CAM, data->nb_lines), 1);
	if (check_position(elems[1], data) || check_vector(elems[2], data)
		|| check_fov(elems[3]))
		return (1);
	camera.position = get_position(elems[1]);
	camera.vector = get_position(elems[2]);
	camera.fov = ft_atoi(elems[3]) * DEG_2_RAD;
	data->scene.camera = camera;
	return (0);
}
