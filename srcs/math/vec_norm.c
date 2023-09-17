/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:13:42 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 22:10:12 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vec_norm(t_vector *a)
{
	double	len;

	len = vec_len(a);
	return ((t_vector){a->x / len, a->y / len, a->z / len});
}

/* Normalizing refers to the process of making something “standard” or, well,
“normal.” In the case of vectors,
let’s assume for the moment that a standard vector has a length of 1.
To normalize a vector, therefore, is to take a vector of any length and,
keeping it pointing in the same direction,
change its length to 1, turning it into what is called a unit vector. */
