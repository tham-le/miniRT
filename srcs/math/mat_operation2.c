/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_operation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:10:42 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/18 19:36:17 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"

static double	cofactor4(const t_mat4 *mat4, int row, int col)
{
	t_mat3	mat3;

	submat4(&mat3, mat4, row, col);
	if ((row + col) % 2 == 1)
		return (det3(&mat3));
	return (-det3(&mat3));
}

static double	det4(const t_mat4 *mat4)
{
	return (cofactor4(mat4, 0, 0) * (*mat4)[0][0]
			+cofactor4(mat4, 0, 1) * (*mat4)[0][1]
			+cofactor4(mat4, 0, 2) * (*mat4)[0][2]
			+cofactor4(mat4, 0, 3) * (*mat4)[0][3]);
}

void	mat_inverse(t_mat4 *res, const t_mat4 *mat)
{
	double	det;
	int		row;

	det = det4(mat);
	if (fabs(det) < EPSILON)
		return ;
	row = 0;
	while (row < 4)
	{
		(*res)[0][row] = cofactor4(mat, row, 0) / det;
		(*res)[1][row] = cofactor4(mat, row, 1) / det;
		(*res)[2][row] = cofactor4(mat, row, 2) / det;
		(*res)[3][row] = cofactor4(mat, row, 3) / det;
		row++;
	}
}
