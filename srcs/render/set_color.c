/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:16:23 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 18:58:18 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	set_color(t_data *data, int x, int y, int color_int)
{
	char	*dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return (ERROR);
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color_int;
	return (SUCESS);
}
