/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:44:43 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/15 17:01:00 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

/* The dot product of two vectors is a scalar.
** enables us to easily find the angle between two vectors.
** the vectors with their tails at the same point.
** For two vectors →a=⟨a1,...,an⟩ and →b=⟨b1,...,bn⟩ in Rn,
** the dot product →a⋅→b is the scalar a1b1+⋯+anbn. */

double	vec_dot(t_vector *a, t_vector *b)
{
	double	c;

	c = a->x * b->x + a->y * b->y + a->z * b->z;
	return (c);
}

/*
if theta is the angle between two vectors a and b, then
a · b = |a| |b| cos theta (1)
where |a| and |b| are the magnitudes of vectors a and b, respectively.
if a.b = 0 then they are perpendicular */
