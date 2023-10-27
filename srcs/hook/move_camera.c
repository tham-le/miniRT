/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:02:19 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 20:04:30 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	*sphere_to_xyz(t_vector *vec, \
double phi, double theta, double r)
{
	vec->x = r * sin(phi) * cos(theta);
	vec->z = r * sin(phi) * sin(theta);
	vec->y = r * cos(phi);
	vec->w = 0;
	return (vec);
}

void	move_camera2(int key, t_data *data)
{
	if (key == XK_Up)
		data->scene.camera.phi += 0.05;
	if (key == XK_Down)
		data->scene.camera.phi -= 0.05;
	if (key == XK_Left)
		data->scene.camera.theta += 0.05;
	if (key == XK_Right)
		data->scene.camera.theta -= 0.05;
	if (key == XK_Up || key == XK_Down || key == XK_Left \
	|| key == XK_Right)
	{
		sphere_to_xyz(&data->scene.camera.vector, \
		data->scene.camera.phi, data->scene.camera.theta, 1);
		data->key = 1;
	}
}

void	change_camera2(int key, t_data *data, t_vector *vec_x, t_vector *vec_z)
{
	if (key == XK_w)
		sphere_to_xyz(vec_z, data->scene.camera.phi, \
		data->scene.camera.theta, SP);
	if (key == XK_s)
		sphere_to_xyz(vec_z, data->scene.camera.phi, \
		data->scene.camera.theta, -SP);
	if (key == XK_a)
		sphere_to_xyz(vec_x, M_PI_2, \
		data->scene.camera.theta - M_PI_2, -SP);
	if (key == XK_d)
		sphere_to_xyz(vec_x, M_PI_2, \
		data->scene.camera.theta - M_PI_2, SP);
}

void	move_camera(int key, t_data *data)
{
	t_vector	vec_x;
	t_vector	vec_y;
	t_vector	vec_z;

	vec_x = (t_vector){0, 0, 0, 0};
	vec_y = (t_vector){0, 0, 0, 0};
	vec_z = (t_vector){0, 0, 0, 0};
	change_camera2(key, data, &vec_x, &vec_y);
	if (key == XK_q)
		vec_y.y = 0.35;
	if (key == XK_e)
		vec_y.y = -0.35;
	if (key == XK_w || key == XK_s || key == XK_a \
	|| key == XK_d || \
		key == XK_q || key == XK_e)
	{
		add_vec(&data->scene.camera.position, \
		&data->scene.camera.position, &vec_x);
		add_vec(&data->scene.camera.position, \
		&data->scene.camera.position, &vec_y);
		add_vec(&data->scene.camera.position, \
		&data->scene.camera.position, &vec_z);
		data->key = 1;
	}
}
