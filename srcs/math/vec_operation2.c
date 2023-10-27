/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:48:06 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 20:25:50 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "mathRT.h"

double	vec_magnitude(const t_vector *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y \
			+ vec->z * vec->z));
}

void	normalize_vec(t_vector *vec)
{
	if (vec_magnitude(vec) == 0)
		return ;
	scale_vec(vec, vec, 1 / vec_magnitude(vec));
	vec->w = 0;
}

double	dot_product(const t_vector *v1, const t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + v1->w * v2->w);
}

void	cross_product(t_vector *res, const t_vector *v1, const t_vector *v2)
{
	res->x = v1->y * v2->z - v1->z * v2->y;
	res->y = v1->z * v2->x - v1->x * v2->z;
	res->z = v1->x * v2->y - v1->y * v2->x;
	res->w = 0;
}

double	vec_distance(const t_vector *v1, const t_vector *v2)
{
	t_vector	sub;

	sub_vec(&sub, v1, v2);
	return (vec_magnitude(&sub));
}
