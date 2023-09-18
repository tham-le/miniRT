/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:10:50 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/18 23:45:31 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_vector	vec_cross(t_vector a, t_vector b)
{
	return ((t_vector){a.y * b.z - a.z * b.y, \
						a.z * b.x - a.x * b.z, \
						a.x * b.y - a.y * b.x});
}

/* c is perpendicular to both a and b, t parallel to each other
 this means that →a×→b has only two possible directions  */

 // the cross product has direction given by the right hand rule
 // length of the cross product is the area of the parallelogram
 // spanned by the two vectors

 // || a x b || = ||a|| ||b|| sin theta;

// proprety of cross product a, b, w is vectors and c is a scalar
// a x b = - (b x a)				anticommunative
// a x (b + c) = a x b + a x c		distributive
// c(a x b) = (ca) x b = a x (cb)	multiplication by a constant
// a x 0 = 0 x a = 0				zero vector
// a x a = 0					  	cross product of a vector with itself is zero
// a . (b x u) = (a x b) . u		scalar triple product

