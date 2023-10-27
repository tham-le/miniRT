/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:55:29 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 17:41:17 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"

t_color	stripe_pattern(t_intersect *itx, t_vector point)
{
	t_vector	transf_point;
	t_mat4		pattern_transf;
	t_color		mixed;

	scaling_matrix(&pattern_transf, itx->obj->scale.x * 4.,
		itx->obj->scale.y * 4., itx->obj->scale.z * 4.0);
	mat_vec_multiply(&transf_point, &itx->obj->inv_transf, &point);
	mat_vec_multiply(&transf_point, &pattern_transf, &transf_point);
	transf_point.x += 0.5;
	transf_point.y += 0.5;
	transf_point.z += 0.5;
	if ((int) floorf(transf_point.x) % 2 == 0)
	{
		mult_color(&mixed, &itx->obj->color, 0.5);
		return (mixed);
	}
	return (itx->obj->color);
}

/*That uv_pattern_at() function will multiply u and v by 
(respectively) the width and height of the pattern, 
round each down to the nearest whole number, 
and add them together. If the result modulo 2 is zero, 
return color_a. Otherwise, return color_b.*/

t_color	checker_pattern(t_intersect *itx, t_vector *point)
{
	double			u;
	double			v;
	t_vector		transformed_point;
	t_color			mixed;

	mat_vec_multiply(&transformed_point, &itx->obj->inv_transf, point);
	if (itx->obj->type == SPHERE)
		sphere_map(&u, &v, &transformed_point);
	else if (itx->obj->type == CONE)
		cone_map(&u, &v, &transformed_point);
	else if (itx->obj->type == CYLINDER)
		cylinder_map(&u, &v, &transformed_point);
	else
		plan_map(&u, &v, &transformed_point);
	if ((int)(floor(u * 40) + floor(v * 20)) % 2 == 0)
	{
		mult_color(&mixed, &itx->obj->color, 0.5);
		return (mixed);
	}
	return (itx->obj->color);
}

t_color	get_obj_color(t_intersect *itx)
{
	t_color	shape_color;

	shape_color = itx->obj->color;
	if (itx->obj->pattern_type == PLAIN)
		return (shape_color);
	else if (itx->obj->pattern_type == CHECKER)
		shape_color = checker_pattern(itx, &itx->over_point);
	else if (itx->obj->pattern_type == STRIPE)
		shape_color = stripe_pattern(itx, itx->over_point);
	return (shape_color);
}
/*	if (itx->obj->bmp_img != NULL)
		shape_color = get_texture_color(itx);*/
/*t_color	tex_colot_at(t_bumpmap	*bmp, int u, int v)
{
	t_color			color;
	int				index;
	unsigned int	*ptr;

	index = v * bmp->line_length + u * (bmp->bpp / 8 );
	printf("index = %i\n", index);
	ptr = (unsigned int *)bmp->addr_bmp + index;
	//printf("ptr = %i\n", *ptr);
	//printf("char %i\n",index);
	color.r = (double)((*ptr >> 16) & 0xFF) / 255.0;
	color.g = (double)((*ptr >> 8) & 0xFF) / 255.0;
	color.b = (double)(*ptr & 0xFF) / 255.0;
	return (color);	
}

t_color    texture_mapping(t_intersect *itx, double u, double v)
{

	v = 1 - v;
	// u = floor(u * (itx->obj->bmp_img->bmp_height -1));
	// v = floor(v * (itx->obj->bmp_img->bmp_width - 1));
	//printf("TEST  u %f v %f\n", u, v);
	u = (int)floor(u * (itx->obj->bmp_img->bmp_height - 1))
	 % itx->obj->bmp_img->bmp_height;
	v = (int)floor(v * (itx->obj->bmp_img->bmp_width - 1)) 
	 % itx->obj->bmp_img->bmp_width;
	
	if (u >= itx->obj->bmp_img->bmp_height ||
	 v >= itx->obj->bmp_img->bmp_width)
		return (itx->obj->color);
	return (tex_colot_at(itx->obj->bmp_img, u, v));
}*/
/*t_color	get_texture_color(t_intersect *itx)
{
	t_vector	shape_point;
	double		u;
	double		v;

	mat_vec_multiply(&shape_point, &itx->obj->inv_transf, &itx->over_point);
	if (itx->obj->type == CYLINDER || itx->obj->type == CONE)
	{
		shape_point.y /= itx->obj->height;
		shape_point.y -= 0.5;
		cylinder_map(&u, &v, &shape_point);
	}
	else if (itx->obj->type == SPHERE)
		sphere_map(&u, &v, &shape_point);
	else
		plan_map(&u, &v, &shape_point);
	if (u < 0 || v < 0)
		return (itx->obj->color);
	return (texture_mapping(itx, u, v));

}*/
