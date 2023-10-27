/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:40:22 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 22:14:15 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"

void	init_obj_value(t_objs	*obj)
{
	obj->diffuse = 0.9;
	obj->highlighted = true;
	obj->reflective = 0.1;
	obj->shininess = 200;
	obj->specular = 0.9;
	obj->pattern_type = PLAIN;
	identity_matrix(&obj->added_rots);
}
