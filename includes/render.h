/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:13:03 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/14 17:02:05 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "miniRT.h"
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

typedef	struct s_intersect
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

int		get_rgb(t_color color);
void	calculate_obj_transforms(t_objs *obj);
void	ray_to_pixel(t_camera *camera, t_ray *ray, double x, double y);
void	render_ray(t_data *data, t_intersect_list *arr, int x, int y);
int		render(t_data *data);
void	calculate_camera_transform(t_scene *scene);
int		set_color(t_data *data, int x, int y, int color_int);
void	calcul_transform(t_data	*data);
bool	intersect_sphere(t_ray *ray, t_intersect_list *xs,\
				t_objs *sphere);
bool	intersect_plane(const t_ray *ray, t_objs *plane,
		t_intersect_list *xs);
bool	intersect_cylinder(const t_ray *ray, t_objs *obj,
	t_intersect_list *xs);
bool	intersect_cone(const t_ray *ray, t_objs *shape, t_intersect_list *xs);
bool	intersect_triangle(t_ray *ray, t_objs *triangle, t_intersect_list *xs);
void	camera_transform(t_scene *scene);
void	view_transform(t_mat4 *res, const t_vector *from, const t_vector *up,
			const t_vector *forward);


#endif
