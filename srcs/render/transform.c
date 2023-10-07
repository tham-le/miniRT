/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:17:55 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/07 20:12:50 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathRT.h"
#include "miniRT.h"
#include "structs.h"

void	multiply_transforms(t_objs *obj, t_mat4 *scale, t_mat4 *rot,
	t_mat4 *translate)
{
	t_mat4	temp;

	mat_multiply(&obj->transf, translate, &obj->added_rots);
	ft_memcpy(&temp, &obj->transf, sizeof(t_mat4));
	mat_multiply(&obj->transf, &temp, rot);
	ft_memcpy(translate, &obj->transf, sizeof(t_mat4));
	mat_multiply(&obj->transf, translate, scale);
	mat_inverse(&obj->inv_transf, &obj->transf);
	// if (obj->type == CONE)
	// {
	// 	translate_matrix(&temp, 0, 0.5, 0);
	// 	mat_multiply(&obj->inv_transf, &temp, &obj->inv_transf);
	// }
	ft_memcpy(&obj->norm_transf, &obj->inv_transf, sizeof(t_mat4));
	transpose_matrix(&obj->norm_transf);
}

void	object_transform(t_objs *obj)
{
	t_mat4	scale;
	t_mat4	rot;
	t_mat4	translate;

	obj->scale = (t_vector){obj->radius, obj->radius, obj->radius, 1};
	identity_matrix(&obj->transf);
	identity_matrix(&scale);
	identity_matrix(&rot);
	identity_matrix(&translate);
	if (obj->type == SPHERE)
		scaling_matrix(&scale, obj->scale.x,
			obj->scale.y, obj->scale.z);
	// if (obj->type == CYLINDER)
	// 	scaling_matrix(&scale, obj->props.scale.x,
	// 		1, obj->props.scale.z);
	// if (obj->type == CONE)
	// 	scaling_matrix(&scale, obj->props.radius * 2,
	// 		obj->props.height * 2, obj->props.radius * 2);
	// if (obj->type == PLANE || obj->type == CYLINDER
	// 	|| obj->type == CONE)
	// 	calculate_orientation(&rot, obj);
	translate_matrix(&translate, obj->position.x,
		obj->position.y, obj->position.z);
	multiply_transforms(obj, &scale, &rot, &translate);
}

/* Calculates the transformation matrices for every object in the scene
 * The chosen transformation order is scale -> rotation -> translation */
void	calcul_transform(t_data	*data)
{
	t_objs	*obj;
	t_light	*light;

	camera_transform(&data->scene);
	obj = data->objs;
	while (obj)
	{
		object_transform(obj);
		obj = obj->next;
	}
	light = data->scene.light;
	while (light)
	{
		normalize_vec(&light->dir);
		mat_vec_multiply(&light->dir, &light->added_rots, &light->dir);
		light = light->next;
	}

}
