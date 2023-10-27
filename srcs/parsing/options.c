/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:54:34 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 22:14:18 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parsing.h"
#include <stdbool.h>
#include <stdio.h>

int	get_pattern_type(char *ptrn)
{
	if (!ft_strcmp(ptrn, "PLAIN"))
		return (PLAIN);
	else if (!ft_strcmp(ptrn, "CHECKER"))
		return (CHECKER);
	else if (!ft_strcmp(ptrn, "STRIPE"))
		return (STRIPE);
	return (PATTERN_ERROR);
}

bool	add_pattern_type(t_objs *obj, char **elems, int i)
{
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-ptrn:", elems[i], 6))
		{
			obj->pattern_type = get_pattern_type(elems[i] + 6);
			if (obj->pattern_type == PATTERN_ERROR)
				return (printf(ERROR_PTRN_ARGS), false);
			return (true);
		}
		i++;
	}
	return (true);
}

bool	check_options(char **elems, int i)
{
	while (i < ft_tabsize(elems))
	{
		if (ft_strncmp("-refl:", elems[i], 6)
			&& ft_strncmp("-diff:", elems[i], 6)
			&& ft_strncmp("-shine:", elems[i], 7)
			&& ft_strncmp("-spec:", elems[i], 6)
			&& ft_strncmp("-ptrn:", elems[i], 6))
			return (printf(ERROR_OPT_ARGS), false);
		i++;
	}
	return (true);
}

bool	add_options(t_objs *obj, char **elems, int i)
{
	if (ft_tabsize(elems) <= i)
		return (true);
	if (check_options(elems, i) == false)
		return (false);
	if (add_reflect_opt(obj, elems, i) == false)
		return (false);
	if (add_diffuse_opt(obj, elems, i) == false)
		return (false);
	if (add_shine_opt(obj, elems, i) == false)
		return (false);
	if (add_specular_opt(obj, elems, i) == false)
		return (false);
	if (add_pattern_type(obj, elems, i) == false)
		return (false);
	return (true);
}
/*else if (!ft_strcmp(ptrn, "RING"))
	return (RING);
else if (!ft_strcmp(ptrn, "GRADIENT"))
	return (GRADIENT);
else if (!ft_strcmp(ptrn, "NOISE"))
	return (NOISE);
else if (!ft_strcmp(ptrn, "MARBLE"))
	return (MARBLE);
*/
