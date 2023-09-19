/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:31:50 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/18 23:45:16 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

// If A and B are matrices of the same size, then they can be added.
// (This is similar to the restriction on adding vectors, namely,
//  only vectors from the same space R n can be added;
//  you cannot add a 2‐vector to a 3‐vector, for example.)
//  If A = [aij] and B = [bij] are both m x n matrices,
//  then their sum, C = A + B, is also an m x n matrix,
//  and its entries are given by the formula cij = aij + bij.

t_vector	vec_add(t_vector a, t_vector b)
{
  return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}
