/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_and_diffuse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:08:30 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:45:09 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	calculate_specular(t_vector *reflect_v, t_intersect *itx,
			t_phong *phong, t_light *light)
{
	double	reflect_dot_eye;

	reflect_dot_eye = dot_product(reflect_v, &itx->eye);
	if (reflect_dot_eye <= 0)
		ft_bzero(&phong->specular, sizeof(t_color));
	else
		mult_color(&phong->specular, &light->color,
			itx->obj->specular * \
			pow(reflect_dot_eye, itx->obj->shininess)
			* light->ratio);
}

t_color	get_ambient(t_scene *scene, t_color patter_color)
{
	t_color	ambient;

	mult_color(&ambient, &patter_color,
		scene->ambient.ratio);
	blend_colors(&ambient, &ambient, &scene->ambient.color);
	return (ambient);
}

bool	is_shadowed(t_data	*data, t_light *light, t_vector *itx_point,
			double *angle)
{
	double				distance;
	t_ray				ray;
	t_intersect_list	arr;
	t_intersect			*itx;
	t_objs				*obj;

	(void)angle;
	sub_vec(&ray.direction, &light->position, itx_point);
	distance = vec_magnitude(&ray.direction);
	scale_vec(&ray.direction, &ray.direction, 1 / distance);
	ray.origin = *itx_point;
	arr.count = 0;
	obj = data->objs;
	while (obj)
	{
		intersect(&ray, obj, &arr);
		obj = obj->next;
	}
	itx = hit(&arr);
	if (itx && itx->t < distance)
		return (true);
	return (false);
}

/*if (check_spotlight(data, &ray, angle) == true)
		return (true);*/

void	reflect_vector(t_vector *res, t_vector *in_vector, t_vector *normal)
{
	scale_vec(res, normal, dot_product(in_vector, normal) * 2);
	sub_vec(res, in_vector, res);
}

bool	specular_and_diffuse(t_data *data, t_light *light,
	t_intersect *itx, t_phong *phong)
{
	double		light_dot_normal;
	t_vector	light_v;
	t_vector	reflect_v;
	double		spotlight_angle;

	spotlight_angle = 0;
	sub_vec(&light_v, &light->position, &itx->over_point);
	normalize_vec(&light_v);
	itx->normal.w = 0;
	light_dot_normal = dot_product(&light_v, &itx->normal);
	if (light_dot_normal < 0 || is_shadowed(data, light, &itx->over_point,
			&spotlight_angle))
		return (false);
	mult_color(&phong->diffuse, &phong->effective_color, light_dot_normal
		* itx->obj->diffuse * light->ratio);
	negate_vec(&light_v, &light_v);
	reflect_vector(&reflect_v, &light_v, &itx->normal);
	calculate_specular(&reflect_v, itx, phong, light);
	return (true);
}

		// if (lights.type == SPOT
	// 	&& acos(spotlight_angle) > lights.theta * 0.9 / 4)
	// 	mult_color(&phong->diffuse, &phong->diffuse, 0.8);
