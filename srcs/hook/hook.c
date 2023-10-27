/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:34:39 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 18:49:24 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "structs.h"
#include "miniRT.h"

int	red_cross(t_data *data)
{
	clean(data, 5);
	printf("Exit\n");
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		printf("Exit\n");
		clean(data, 5);
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &red_cross, data);
	mlx_loop(data->mlx_ptr);
}
/*
t_vector	*sphere_to_xyz(t_vector *vec, \
double phi, double theta, double r)
{
	vec->x = r * sin(phi) * cos(theta);
	vec->z = r * sin(phi) * sin(theta);
	vec->y = r * cos(phi);
	vec->w = 0;
	return (vec);
}



void	move_camera(int key, t_data *data)
{
	t_vector	vec_x;
	t_vector	vec_y;
	t_vector	vec_z;

	vec_x = (t_vector){0, 0, 0, 0};
	vec_y = (t_vector){0, 0, 0, 0};
	vec_z = (t_vector){0, 0, 0, 0};
	if (key == XK_w)
		sphere_to_xyz(&vec_z, data->scene.camera.phi, \
		data->scene.camera.theta, SP);
	if (key == XK_s)
		sphere_to_xyz(&vec_z, data->scene.camera.phi, \
		data->scene.camera.theta, -SP);
	if (key == XK_a)
		sphere_to_xyz(&vec_x, M_PI_2, \
		data->scene.camera.theta - M_PI_2, -SP);
	if (key == XK_d)
		sphere_to_xyz(&vec_x, M_PI_2, \
		data->scene.camera.theta - M_PI_2, SP);
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

int	key_press(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		printf("Exit\n");
		clean(data, 5);
	}
	if (key == XK_w || key == XK_s || key == XK_a \
	|| key == XK_d || \
		key == XK_q || key == XK_e)
		move_camera(key, data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (data->key == 1 && (key == XK_w || key == XK_s \
	|| key == XK_a || key == XK_d || \
		key == XK_q || key == XK_e))
	{
		calcul_transform(data);
		render(data);
		data->key = 0;
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, \
	KeyPressMask, &key_press, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, \
	&key_release, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &red_cross, data);
	mlx_loop(data->mlx_ptr);
}
*/
