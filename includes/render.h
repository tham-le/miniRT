/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:13:03 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 17:55:32 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "miniRT.h"
# include "structs.h"
# include <math.h>

/* A ray being cast from the screen with a direction and origine */
typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
	double		t;
	int			hit;
	t_color		color;
}				t_ray;

typedef struct s_intersect
{
	double		t;
	t_objs		*obj;
	t_vector	point;
	t_vector	normal;
	t_vector	eye;
	t_vector	reflect;
	t_vector	over_point;
	bool		inside;
}				t_intersect;

typedef struct s_inetrsect_list
{
	t_intersect	arr[MAX_INTERSECT];
	int			count;
}				t_intersect_list;

//Functions from file : get_obj_color.c
t_color			stripe_pattern(t_intersect *itx, t_vector point);

t_color			checker_pattern(t_intersect *itx, t_vector *point);

t_color			get_obj_color(t_intersect *itx);

//Functions from file : set_color.c
int				set_color(t_data *data, int x, int y, int color_int);

//Functions from file : reflection.c
t_color			reflection_color(t_intersect *itx, t_data *data, \
int remaining, t_light *light);

t_color			cast_reflection_ray(t_data	*data, t_intersect *intersection,
					int reflection_depth, t_light	*light);

//Functions from file : transform.c
void			calculate_orientation(t_mat4 *rot_transform, t_objs *shape);

void			object_transform(t_objs *obj);

void			calcul_transform(t_data *data);

//Functions from file : camera.c
void			camera_transform(t_scene *scene);

//Functions from file : normal_at.c
t_vector		cylinder_normal(const t_objs *shape, \
const t_vector *itx_point);

t_vector		cone_normal(const t_objs *shape, const t_vector *itx_point);

t_vector		triangle_normal(const t_objs *shape, \
const t_vector *itx_point);

t_vector		normal_at(const t_objs *obj, const t_vector *itx_point);

//Functions from file : intersect_cylinder.c
bool			intersect_cylinder(const t_ray *ray, t_objs *obj,
					t_intersect_list *xs);
//Functions from file : intersect_cone.c

////Functions from file : intersect_sphere.c
bool			intersect_sphere(t_ray *ray, t_intersect_list *xs, \
					t_objs *sphere);
bool			intersect_plane(const t_ray *ray, t_objs *plane,
					t_intersect_list *xs);
bool			intersect_cone(const t_ray *ray, t_objs *shape, \
					t_intersect_list *xs);

//Functions from file : intersect_triangle.c
bool			intersect_triangle(t_ray *ray, t_objs *triangle, \
					t_intersect_list *xs);

//Functions from file : render.c
t_intersect		*hit(t_intersect_list *xs);

t_color			shading(t_intersect *itx, t_data *data, t_light *light);

t_color			shade( t_data *data, t_intersect_list *arr, t_ray *ray);

int				render(t_data *data);

//Functions from file : ray_to_pixel.c
void			ray_to_pixel(t_camera *camera, t_ray *ray, double x, \
					double y);

//Functions from file : specular_and_diffuse.c
t_color			get_ambient(t_scene *scene, t_color patter_color);

void			reflect_vector(t_vector *res, t_vector *in_vector, \
t_vector *normal);

//Functions from file : intersect.c
void			intersect(t_ray *ray, t_objs *obj, t_intersect_list *arr);

//Functions from file : uv_map.c
void			cone_map(double *u, double *v, t_vector *point);

void			cylinder_map(double *u, double *v, t_vector *point);

void			plan_map(double *u, double *v, t_vector *point);

void			sphere_map(double *u, double *v, t_vector *point);

//Functions from file : get_rgb.c
unsigned int	get_rgb(t_color color);

bool			specular_and_diffuse(t_data *data, t_light *light, \
					t_intersect *itx, t_phong *phong);

//Functions from file : pre_computation.c
void			pre_computations(t_intersect *intersection, t_ray *ray);

#endif
