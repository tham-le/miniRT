/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:27:32 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/06 20:06:48 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static unsigned int	clamp_color(double color)
{
	color *= 255;
	if (color > 255)
		return (255);
	if (color < 0)
		return (0);
	return (color);
}

unsigned int	get_rgb(t_color color)
{
	return (clamp_color(color.r) << 16 \
			| clamp_color(color.g) << 8 \
			| clamp_color(color.b));
}
