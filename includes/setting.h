/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:16:11 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 17:43:44 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

#include "structs.h"

/*
hzie : horizontal size (in pixels) of the canvas										that the picture
 *              will be rendered to..
vsize : vertical size (in pixels).
half_width Stores the camera's half hsize value.
half_height Stores the camera's half vsize value.
pixel_size Stores the camera's pixel size
calculated from half_width and hsize values*/
typedef struct	s_settings
{
	float			hsize;
	float			vsize;
	float			aspect_ratio;
	float			half_width;
	float			half_height;
	float			pixel_size;
	}				t_settings;



#endif
