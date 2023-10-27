/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:54:34 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 17:44:38 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_pattern_type(char *ptrn)
{
	if (!ft_strcmp(ptrn, "PLAIN"))
		return (PLAIN);
	else if (!ft_strcmp(ptrn, "CHECKER"))
		return (CHECKER);
	else if (!ft_strcmp(ptrn, "STRIPE"))
		return (STRIPE);
	else if (!ft_strcmp(ptrn, "RING"))
		return (RING);
	else if (!ft_strcmp(ptrn, "GRADIENT"))
		return (GRADIENT);
	else if (!ft_strcmp(ptrn, "NOISE"))
		return (NOISE);
	else if (!ft_strcmp(ptrn, "MARBLE"))
		return (MARBLE);
	return (-1);
}

void	add_pattern_type(t_objs *obj, char **elems)
{
	int			i;

	i = 3;
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-ptrn:", elems[i], 6))
		{
			obj->pattern_type = get_pattern_type(elems[i] + 6);
			return ;
		}
		i++;
	}
}

void	add_options(t_objs *obj, char **elems)
{
	add_reflect_opt(obj, elems);
	add_diffuse_opt(obj, elems);
	add_shine_opt(obj, elems);
	add_specular_opt(obj, elems);
	add_pattern_type(obj, elems);
}
