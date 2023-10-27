/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itchinda <itchinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:12:01 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 21:45:15 by itchinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "mathRT.h"
#include "miniRT.h"
#include "structs.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>

t_intersect	*hit(t_intersect_list *xs)
{
	double	min_t;
	int		i;
	int		idx;

	i = 0;
	idx = 0;
	min_t = INFINITY;
	while (i < xs->count)
	{
		if (xs->arr[i].t >= EPSILON && xs->arr[i].t < min_t)
		{
			min_t = xs->arr[i].t;
			idx = i;
		}
		i++;
	}
	if (min_t == INFINITY)
		return (NULL);
	return (&xs->arr[idx]);
}

// Phong shading model
t_color	shading(t_intersect *itx,	t_data *data, t_light *light)
{
	t_phong			phong;
	t_color			result;
	t_color			shape_color;
	const double	light_dist = vec_distance(&itx->point, &light->position);
	const double	attenuation = (100 * light->ratio \
	- light_dist) / (100 * data->scene.light->ratio - 1);

	shape_color = get_obj_color(itx);
	blend_colors(&phong.effective_color, &shape_color,
		&light->color);
	if (specular_and_diffuse(data, light, itx, &phong) == false)
		return (get_ambient(&data->scene, shape_color));
	result = get_ambient(&data->scene, shape_color);
	if (attenuation < 0)
		return (result);
	else if (attenuation > 0 && attenuation <= 1)
	{
		mult_color(&phong.diffuse, &phong.diffuse, attenuation);
		mult_color(&phong.specular, &phong.specular, attenuation);
	}
	result.r += phong.diffuse.r + phong.specular.r;
	result.g += phong.diffuse.g + phong.specular.g;
	result.b += phong.diffuse.b + phong.specular.b;
	return (result);
}

t_color	shade( t_data *data, t_intersect_list *arr, t_ray *ray)
{
	t_intersect		*itx;
	t_light			*light;
	t_color			final_color;
	t_color			surface_color;
	t_color			reflected;

	itx = hit(arr);
	ft_bzero(&final_color, sizeof(t_color));
	if (itx != NULL)
	{
		pre_computations(itx, ray);
		light = data->scene.light;
		while (light)
		{
			surface_color = shading(itx, data, light);
			reflected = cast_reflection_ray(data, itx,
					data->reflection_depth, light);
			add_colors(&final_color, &final_color, &surface_color);
			add_colors(&final_color, &final_color, &reflected);
			light = light->next;
		}
	}
	return (final_color);
}

int	render(t_data *data)
{
	t_intersect_list	arr;
	int					x;
	int					y;
	t_ray				ray;
	t_objs				*obj;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			ray_to_pixel(&data->scene.camera, &ray, x + 0.5, y + 0.5);
			arr.count = 0;
			obj = data->objs;
			while (obj)
			{
				intersect(&ray, obj, &arr);
				obj = obj->next;
			}
			set_color(data, x, y, get_rgb(shade(data, &arr, &ray)));
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	printf("Render done\n");
	return (SUCESS);
}
