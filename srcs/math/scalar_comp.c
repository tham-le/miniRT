/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:05:24 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 22:09:41 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "math_vec.h"

/* The scalar component of b in the direction of a is
b . the unit vector in thr direction a, the legnth of a here is irrelevent */

double	scalar_comp(t_vector *a, t_vector *b)
{
	return (vec_dot(a, b) / vec_len(a));
}
