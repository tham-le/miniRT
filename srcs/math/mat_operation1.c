/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_operation1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:55:03 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 20:26:17 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"

/**
 * Returns a determinant of a 2x2 matrix
 */
static double	det2(const t_mat2 *mat)
{
	return ((*mat)[0][0] * (*mat)[1][1] - (*mat)[0][1] * (*mat)[1][0]);
}

/**
 * Computes a 2x2 submatrix of a 3x3 matrix
 */
static void	submat3(t_mat2 *res, const t_mat3 *mat, int row, int col)
{
	int	i;
	int	j;
	int	i_sub;
	int	j_sub;

	i = -1;
	i_sub = 0;
	while (++i < 3)
	{
		if (i == row)
			continue ;
		j_sub = 0;
		j = 0;
		while (j < 3)
		{
			if (j == col)
				j++;
			else
				(*res)[i_sub][j_sub++] = (*mat)[i][j++];
		}
		i_sub++;
	}
}

/** Computes a 3x3 submatrix of a 4x4 matrix*/
void	submat4(t_mat3 *res, const t_mat4 *mat, int row, int col)
{
	int	i;
	int	j;
	int	i_sub;
	int	j_sub;

	i = -1;
	i_sub = 0;
	while (++i < 4)
	{
		if (i == row)
			continue ;
		j_sub = 0;
		j = 0;
		while (j < 4)
		{
			if (j == col)
				j++;
			else
				(*res)[i_sub][j_sub++] = (*mat)[i][j++];
		}
		i_sub++;
	}
}

/**
 *  Returns the cofactor of a matrix at a mat[row][col]
 */
static double	cofactor3(const t_mat3 *mat3, int row, int col)
{
	t_mat2	mat2;

	submat3(&mat2, mat3, row, col);
	if ((row + col) % 2 == 1)
		return (det2(&mat2));
	return (-det2(&mat2));
}

/**
 * Returns the determinant of a 3x3 matrix
 */
double	det3(const t_mat3 *mat3)
{
	return (cofactor3(mat3, 0, 0) * (*mat3)[0][0]
			+ cofactor3(mat3, 0, 1) * (*mat3)[0][1]
			+ cofactor3(mat3, 0, 2) * (*mat3)[0][2]);
}
