/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:13:03 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 21:22:13 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "miniRT.h"

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
	double		t;
	int			hit;
	t_color		color;
}				t_ray;

int		draw(t_data *data);
int		get_rgb(t_color color);
int		set_color(t_data *data, int x, int y, int color_int);
t_ray	ray_to_pixel(t_data *data, int x, int y);
t_color	intersect_color(t_data *data, t_ray *ray);
void	intersect_sphere(t_data *data, t_ray *ray, t_objs *ob);
void    intersect_cylinder(t_ray *ray, t_objs *ob);
void    intersect_plane(t_ray *ray, t_objs *ob);
#endif
