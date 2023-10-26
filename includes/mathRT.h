/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:04:59 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:35:25 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHRT_H
# define MATHRT_H

# include "structs.h"
# include "miniRT.h"

void	add_vec(t_vector *res, const t_vector *v1, const t_vector *v2);
void	sub_vec(t_vector *res, const t_vector *v1, const t_vector *v2);
void	scale_vec(t_vector *res, const t_vector *v, double scale);
void	negate_vec(t_vector *res, const t_vector *v);
void	mat_multiply(t_mat4 *res, const t_mat4 *m1, const t_mat4 *m2);
void	identity_matrix(t_mat4 *mat);
void	transpose_matrix(t_mat4 *mat);
void	translate_matrix(t_mat4 *mat, double x, double y, double z);
void	scaling_matrix(t_mat4 *mat, double x, double y, double z);
void	rotation_matrix_x(t_mat4 *mat, double r);
void	rotation_matrix_y(t_mat4 *mat, double r);
void	axis_angle(t_mat4 *rot_mat, const t_vector *ax, double angle);
void	submat4(t_mat3 *res, const t_mat4 *mat, int row, int col);
double	det3(const t_mat3 *mat3);
void	mat_inverse(t_mat4 *res, const t_mat4 *mat);
double	vec_magnitude(const t_vector *vec);
void	normalize_vec(t_vector *vec);
double	dot_product(const t_vector *v1, const t_vector *v2);
void	cross_product(t_vector *res, const t_vector *v1, const t_vector *v2);
double	vec_distance(const t_vector *v1, const t_vector *v2);
void	mat_vec_multiply(t_vector *res, const t_mat4 *mat,
			const t_vector *vec);
#endif
