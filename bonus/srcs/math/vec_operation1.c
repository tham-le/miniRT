/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:31:50 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/21 19:04:37 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "math.h"

void	add_vec(t_vector *res, const t_vector *v1, const t_vector *v2)
{
	res->x = v1->x + v2->x;
	res->y = v1->y + v2->y;
	res->z = v1->z + v2->z;
	res->w = v1->w + v2->w;
}

void	sub_vec(t_vector *res, const t_vector *v1, const t_vector *v2)
{
	res->x = v1->x - v2->x;
	res->y = v1->y - v2->y;
	res->z = v1->z - v2->z;
	res->w = v1->w - v2->w;
}

void	scale_vec(t_vector *res, const t_vector *v, double scale)
{
	res->x = scale * v->x;
	res->y = scale * v->y;
	res->z = scale * v->z;
	res->w = scale * v->w;
}

void	negate_vec(t_vector *res, const t_vector *v)
{
	res->x = -1 * v->x;
	res->y = -1 * v->y;
	res->z = -1 * v->z;
	res->w = -1 * v->w;
}
