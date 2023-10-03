/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:12:01 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/29 18:24:57 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "miniRT.h"
#include "structs.h"

void	intersect(t_ray	*ray, t_objs *obj, t_intersect_list *arr)
{
	if (arr->count >= MAX_INTERSECT)
		return ;
	if (obj->type == SPHERE)
		intersect_sphere(ray, arr, obj);
	// else if (obj->type == PLAN)
	// 	intersect_plane(ray, obj, arr);
	//transform_ray(ray, obj);
	// else if (obj->type == SQUARE)
	// 	intersect_square(ray, obj, arr);
	// else if (obj->type == CYLINDER)
	// 	intersect_cylinder(ray, obj, arr);
	// else if (obj->type == TRIANGLE)
	// 	intersect_triangle(ray, obj, arr);
}

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
		if (xs->arr[i].t >= 0 && xs->arr[i].t < min_t)
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

void	ray_position(t_vector *pos, const t_ray *ray, double time)
{
	pos->x = ray->direction.x * time + ray->origin.x;
	pos->y = ray->direction.y * time + ray->origin.y;
	pos->z = ray->direction.z * time + ray->origin.z;
	pos->w = 1;
}

void	transform_ray(t_ray *transformed_ray, const t_ray *ray,
	const t_objs *obj)
{
	mat_vec_multiply(&transformed_ray->origin, &obj->inv_transf,
		&ray->origin);
	mat_vec_multiply(&transformed_ray->direction, &obj->inv_transf,
		&ray->direction);
}

t_vector	sphere_normal(t_vector *normal, const t_objs *obj,
				const t_vector *itx_point)
{
	t_vector	world_normal;

	mat_vec_multiply(normal, &obj->inv_transf, itx_point);
	normalize_vec(normal);
	normal->w = 0;
	// if (obj->normal != NULL)
	// 	return (normal_map(normal, obj, itx_point));
	mat_vec_multiply(&world_normal, &obj->norm_transf, normal);
	world_normal.w = 0;
	normalize_vec(&world_normal);
	return (world_normal);
}


t_vector	normal_at(const t_objs *obj, const t_vector *itx_point)
{
	t_vector	normal;
	//t_vector	world_normal;

	if (obj->type == SPHERE)
		return (sphere_normal(&normal, obj, itx_point));
	// else if (obj->type == PLANE)
	// 	return (plane_normal(obj, itx_point));
	// else if (obj->type == CYLINDER)
	// 	return (cylinder_normal(obj, itx_point));
	// else if (obj->type == CONE)
	// 	return (cone_normal(obj, itx_point));
	// normal = cube_normal(obj, itx_point);
	// if (obj->normal_tex != NULL)
	// 	return (normal_map(&normal, obj, itx_point));
	// mat_vec_multiply(&world_normal, &obj->norm_transf, &normal);
	// world_normal.w = 0;
	// normalize_vec(&world_normal);
	ft_bzero(&normal, sizeof(t_vector));
	return (normal);
}

void	reflect_vector(t_vector *res, t_vector *in_vector, t_vector *normal)
{
	scale_vec(res, normal, dot_product(in_vector, normal) * 2);
	sub_vec(res, in_vector, res);
}


void	pre_computations(t_intersect *intersection,
			t_ray *ray)
{
	ray_position(&intersection->point, ray, intersection->t);
	intersection->normal = normal_at(intersection->obj, &intersection->point);
	negate_vec(&intersection->eye, &ray->direction);
	intersection->eye.w = 0;
	intersection->inside = false;
	if (dot_product(&intersection->normal, &intersection->eye) < 0)
	{
		intersection->inside = true;
		negate_vec(&intersection->normal, &intersection->normal);
	}
	scale_vec(&intersection->over_point, &intersection->normal, EPSILON);
	add_vec(&intersection->over_point, &intersection->point,
		&intersection->over_point);
	reflect_vector(&intersection->reflect, &ray->direction,
		&intersection->normal);
}

// t_color	texture_mapping(t_intersect *itx, double u, double v)
// {
// 	if (itx->obj->tex_tile != 0)
// 	{
// 		u = (int)floor(u * (itx->obj->tex_height - 1) * itx->obj->tex_tile) \
// 		% itx->obj->tex_height;
// 		v = (int)floor(v * (itx->obj->tex_width - 1) * itx->obj->tex_tile) \
// 		% itx->obj->tex_width;
// 	}
// 	else
// 	{
// 		u = (int)floor(u * (itx->obj->tex_height - 1));
// 		v = (int)floor(v * (itx->obj->tex_width - 1));
// 	}
// 	if (u >= itx->obj->tex_height || v >= itx->obj->tex_width)
// 		return (itx->obj->props.color);
// 	return (itx->obj->diffuse_tex[(int)u][(int)v]);
// }

// t_color	get_texture_color(t_intersect *itx)
// {
// 	t_vector	shape_point;
// 	double		u;
// 	double		v;

// 	mat_vec_multiply(&shape_point, &itx->obj->inv_transf, &itx->point);
// 	// if (itx->obj->type == CYLINDER || itx->obj->type == CONE)
// 	// {
// 	// 	shape_point.y /= itx->obj->props.height;
// 	// 	shape_point.y -= 0.5;
// 	// 	cylindrical_map(&u, &v, &shape_point);
// 	// }
// 	// else
// 	if (itx->obj->type == SPHERE)
// 		spherical_map(&u, &v, &shape_point);
// 	// else
// 	// 	cubical_map(&u, &v, &shape_point);
// 	// if (u < 0 || v < 0)
// 	// 	return (itx->obj->props.color);
// 	return (texture_mapping(itx, u, v));
// }

// t_color	get_shape_color(t_intersec *itx)
// {
// 	if (itx->obj->diffuse_tex != NULL)
// 		return (get_texture_color(itx));
// 	// if (itx->obj->props.pattern_type == NONE)
// 	// 	return (itx->obj->props.color);
// 	// if (itx->obj->props.pattern_type == STRIPE)
// 	// 	return (stripe_pattern(itx, itx->over_point, int_to_color(0xffffff),
// 	// 			int_to_color(0xff0000)));
// 	// if (itx->obj->props.pattern_type == CHECKER_BOARD)
// 	// 	return (checker_pattern(itx, &itx->over_point));
// 	// if (itx->obj->props.pattern_type == GRADIENT)
// 	// 	return (gradient_pattern(itx, itx->over_point, int_to_color(0xff0000),
// 	// 			int_to_color(0x0000ff)));
// 	// if (itx->obj->props.pattern_type == RING)
// 	// 	return (ring_pattern(itx, itx->over_point, int_to_color(0xff0000),
// 	// 			int_to_color(0x0000ff)));
// 	return (itx->obj->props.color);
// }


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

bool	get_specular_and_diffuse(t_data * data,
	t_intersect *itx, t_phong *phong)
{
	double		light_dot_normal;
	t_vector	light_v;
	t_vector	reflect_v;
	//double		spotlight_angle;

	//spotlight_angle = 0;
	sub_vec(&light_v, &data->scene.light->position, &itx->over_point);
	normalize_vec(&light_v);
	itx->normal.w = 0;
	light_dot_normal = dot_product(&light_v, &itx->normal);
	//|| is_shadowed(scene, light_idx, &itx->over_point,
	//		&spotlight_angle
	if (light_dot_normal < 0)
		return (false);
	mult_color(&phong->diffuse, &phong->effective_color, light_dot_normal
		* itx->obj->diffuse * data->scene.light->ratio);

	// if (scene->lights[light_idx].type == SPOT
	// 	&& acos(spotlight_angle) > scene->lights[light_idx].theta * 0.9 / 4)
	// 	mult_color(&phong->diffuse, &phong->diffuse, 0.8);
	negate_vec(&light_v, &light_v);
	reflect_vector(&reflect_v, &light_v, &itx->normal);
	calculate_specular(&reflect_v, itx, phong, data->scene.light);
	return (true);
}


t_color	shading(t_intersect *itx,	t_data *data)
{
	t_phong			phong;
	t_color			result;
	t_color			shape_color;
	const double	light_dist = vec_distance(&itx->point,\
	&data->scene.light->position);
	const double	attenuation = (100 * data->scene.light->ratio\
	- light_dist) / (100 * data->scene.light->ratio - 1);


	shape_color = itx->obj->color;
	blend_colors(&phong.effective_color, &shape_color,
		&data->scene.light->color);
	if (get_specular_and_diffuse(data, itx, &phong) == false)
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

t_color	shade( t_data *data,t_intersect_list *arr, t_ray *ray)
{
	t_intersect		*itx;
	// int				light_idx;
	t_color			final_color;
	t_color			surface_color;
	// t_color			reflected;

	(void)data;
	(void)ray;
	itx = hit(arr);
	ft_bzero(&final_color, sizeof(t_color));
	ft_bzero(&surface_color, sizeof(t_color));
	if (itx != NULL)
	{
		pre_computations(itx, ray);
		add_colors(&final_color, &final_color, &itx->obj->color);
		surface_color = shading(itx, data);
		// reflected = cast_reflection_ray(scene, itx,
		// 		s_->settings.reflection_depth, light_idx);
		add_colors(&final_color, &final_color, &surface_color);
		// add_colors(&final_color, &final_color, &reflected);
		// light_idx++;
	}
	else
		final_color = data->scene.ambient.color;
	return (final_color);
}


void	render_ray(t_data *data, t_intersect_list *arr, int x, int y)
{
	t_ray	ray;
	t_objs	*obj;
	t_color	color;

	ray_to_pixel(data, &ray, x + 0.5, y + 0.5);
	arr->count = 0;
	obj = data->objs;
	while (obj)
	{
		intersect(&ray, obj, arr);
		obj = obj->next;
	}
	if (arr->count == 0)
		color = data->scene.ambient.color;
	else
		color = data->objs->color;
	//color = shade(data, arr, &ray);
	set_color(data, x, y, get_rgb(color));
}

void	default_objs(t_objs *obj)
{
	obj->diffuse = 0.9;
	obj->highlighted = true;
	obj->reflective= 0.2;
	obj->shininess = 50;
	obj->specular = 0.8;
}

int	render(t_data *data)
{
	t_intersect_list	arr;
	int					x;
	int					y;

	y = -1;
	while (++y < W_H)
	{
		x = -1;
		while (++x < W_W)
			render_ray(data, &arr, x, y);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (SUCESS);
}
