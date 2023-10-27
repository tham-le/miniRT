/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:54:29 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 17:41:01 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	view_transform(t_mat4 *res, const t_vector *from, const t_vector *up,
	const t_vector *forward)
{
	t_vector	left;
	t_vector	true_up;
	t_vector	upn;
	t_mat4		orientation;
	t_mat4		translation;

	upn = *up;
	normalize_vec(&upn);
	cross_product(&left, forward, &upn);
	normalize_vec(&left);
	cross_product(&true_up, &left, forward);
	normalize_vec(&true_up);
	ft_bzero(&orientation, sizeof(t_mat4));
	orientation[0][0] = left.x;
	orientation[0][1] = left.y;
	orientation[0][2] = left.z;
	orientation[1][0] = true_up.x;
	orientation[1][1] = true_up.y;
	orientation[1][2] = true_up.z;
	orientation[2][0] = forward->x * -1;
	orientation[2][1] = forward->y * -1;
	orientation[2][2] = forward->z * -1;
	orientation[3][3] = 1;
	translate_matrix(&translation, from->x * -1, from->y * -1, from->z * -1);
	mat_multiply(res, &orientation, &translation);
}

void	camera_transform(t_scene *scene)
{
	t_vector		from;
	t_vector		up;

	from.x = scene->camera.position.x;
	from.y = scene->camera.position.y;
	from.z = scene->camera.position.z;
	from.w = 0;
	normalize_vec(&scene->camera.vector);
	up.x = 0;
	up.y = 1;
	up.z = 0;
	up.w = 0;
	view_transform(&scene->camera.transform, &from, &up,
		&scene->camera.vector);
	mat_inverse(&scene->camera.inverse, &scene->camera.transform);
}
