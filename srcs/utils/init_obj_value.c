/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:40:22 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/05 17:02:34 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_obj_value(t_objs	*obj)
{
	obj->diffuse = 0.9;
	obj->highlighted = true;
	obj->reflective= 0.5;
	obj->shininess = 50;
	obj->specular = 0.8;
	identity_matrix(&obj->added_rots);
}
