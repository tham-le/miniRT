/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itchinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:22:09 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/19 21:29:25 by itchinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	add_bmp_file(t_objs *obj, char **elems)
{
	int			i;

	i = 3;
	while (i < ft_tabsize(elems))
	{
		if (open(elems[i], O_RDONLY) != -1)
		{
			obj->bump_img = elems[i];
			return ;
		}
		i++;
	}
}

void	add_reflect_opt(t_objs *obj, char **elems)
{
	int			i;

	i = 3;
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-refl:", elems[i], 6))
		{
			if (check_float(elems[i] + 6))
				return ;
			obj->reflective = ft_atod(elems[i] + 6);
			return ;
		}
		i++;
	}
}

void	add_diffuse_opt(t_objs *obj, char **elems)
{
	int			i;

	i = 3;
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-diff:", elems[i], 6))
		{
			if (check_float(elems[i] + 6))
				return ;
			obj->diffuse = ft_atod(elems[i] + 6);
			return ;
		}
		i++;
	}
}

void	add_shine_opt(t_objs *obj, char **elems)
{
	int			i;

	i = 3;
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-shine:", elems[i], 7))
		{
			if (check_float(elems[i] + 7))
				return ;
			obj->shininess = ft_atod(elems[i] + 7);
			return ;
		}
		i++;
	}
}

void	add_specular_opt(t_objs *obj, char **elems)
{
	int			i;

	i = 3;
	while (i < ft_tabsize(elems))
	{
		if (!ft_strncmp("-spec:", elems[i], 6))
		{
			if (check_float(elems[i] + 6))
				return ;
			obj->specular = ft_atod(elems[i] + 6);
			return ;
		}
		i++;
	}
}
