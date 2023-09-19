/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:04:59 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/18 23:46:55 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_VEC_H
# define MATH_VEC_H

#include "miniRT.h"

double	scalar_comp(t_vector a, t_vector b);
t_vector	vec_add(t_vector a, t_vector b);
t_vector	vec_minus(t_vector a, t_vector b);
t_vector	vec_cross(t_vector a, t_vector b);
double		vec_dot(t_vector a, t_vector b);
double	vec_len(t_vector a);
t_vector	vec_norm(t_vector a);
t_vector	vec_scala_multi(t_vector a, double b);

#endif
