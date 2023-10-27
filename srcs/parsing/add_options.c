/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:22:09 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/27 20:30:49 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	add_bmp_file(t_objs *obj, char **elems)
// {
// 	int			i;

// 	i = 3;
// 	while (i < ft_tabsize(elems))
// 	{
// 		if (open(elems[i], O_RDONLY) != -1)
// 		{
// 			obj->bump_img = elems[i];
// 			return ;
// 		}
// 		i++;
// 	}
// }

bool	add_reflect_opt(t_objs *obj, char **elems, int i)
{
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-refl:", elems[i], 6))
		{
			if (check_float(elems[i] + 6))
				return (printf(ERROR_REFL_ARGS_DIGIT), false);
			obj->reflective = ft_atod(elems[i] + 6);
			return (true);
		}
		i++;
	}
	return (true);
}

bool	add_diffuse_opt(t_objs *obj, char **elems, int i)
{
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-diff:", elems[i], 6))
		{
			if (check_float(elems[i] + 6))
				return (printf(ERROR_DIFF_ARGS_DIGIT), false);
			obj->diffuse = ft_atod(elems[i] + 6);
			return (true);
		}
		i++;
	}
	return (true);
}

bool	add_shine_opt(t_objs *obj, char **elems, int i)
{
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-shine:", elems[i], 7))
		{
			if (check_float(elems[i] + 7))
				return (printf(ERROR_SHINE_ARGS_DIGIT), false);
			obj->shininess = ft_atod(elems[i] + 7);
			return (true);
		}
		i++;
	}
	return (true);
}

bool	add_specular_opt(t_objs *obj, char **elems, int i)
{
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-spec:", elems[i], 6))
		{
			if (check_float(elems[i] + 6))
				return (printf(ERROR_SPEC_ARGS_DIGIT), false);
			obj->specular = ft_atod(elems[i] + 6);
			return (true);
		}
		i++;
	}
	return (true);
}
