/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:12:01 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 22:50:42 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "mathRT.h"
#include "miniRT.h"
#include "structs.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

t_intersect	*hit(t_intersect_list *xs)
{
	double	min_t;
	int		i;
	int		idx;
	bool	found;

	i = 0;
	idx = 0;
	min_t = INFINITY;
	found = false;
	while (i < xs->count)
	{
		if (xs->arr[i].t >= EPSILON && xs->arr[i].t < min_t)
		{
			min_t = xs->arr[i].t;
			idx = i;
			found = true;
		}
		i++;
	}
	if (!found)
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

	if (!itx || !itx->obj)
		return ((t_color){0, 0, 0});
	
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
		if (!itx->obj)
			return (final_color);
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

void	*render_thread(void *arg)
{
	t_thread_data		*thread_data;
	t_intersect_list	arr;
	int					x;
	int					y;
	t_ray				ray;
	t_objs				*obj;

	thread_data = (t_thread_data *)arg;
	y = thread_data->start_row - 1;
	while (++y < thread_data->end_row)
	{
		x = -1;
		while (++x < thread_data->data->width)
		{
			ray_to_pixel(&thread_data->data->scene.camera, &ray, x + 0.5, y + 0.5);
			ft_bzero(&arr, sizeof(t_intersect_list));
			arr.count = 0;
			obj = thread_data->data->objs;
			
			while (obj)
			{
				intersect(&ray, obj, &arr);
				obj = obj->next;
			}
			
			set_color(thread_data->data, x, y, get_rgb(shade(thread_data->data, &arr, &ray)));
		}
	}
	return (NULL);
}

int	render(t_data *data)
{
	pthread_t		threads[8];
	t_thread_data	thread_data[8];
	int				num_threads;
	int				rows_per_thread;
	int				extra_rows;
	int				i;

	num_threads = sysconf(_SC_NPROCESSORS_ONLN);
	if (num_threads <= 0 || num_threads > 8)
		num_threads = 8;
	
	rows_per_thread = data->height / num_threads;
	extra_rows = data->height % num_threads;
	
	i = -1;
	while (++i < num_threads)
	{
		thread_data[i].data = data;
		thread_data[i].thread_id = i;
		thread_data[i].start_row = i * rows_per_thread;
		thread_data[i].end_row = (i + 1) * rows_per_thread;
		if (i == num_threads - 1)
			thread_data[i].end_row += extra_rows;
		
		if (pthread_create(&threads[i], NULL, render_thread, &thread_data[i]) != 0)
		{
			ft_putendl("Error: Failed to create thread");
			return (ERROR);
		}
	}
	
	i = -1;
	while (++i < num_threads)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			ft_putendl("Error: Failed to join thread");
			return (ERROR);
		}
	}
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (SUCESS);
}
