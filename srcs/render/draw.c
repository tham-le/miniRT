/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:12:01 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 18:40:56 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

int	ft_draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	printf("hsize: %f, vsize: %f\n", data->settings.hsize, data->settings.vsize);
	while (y < data->settings.hsize)
	{
		x = 0;
		while (x < data->settings.vsize)
		{
			data->objs->color.r = 255.99 * (double)x / (data->settings.vsize - 1);
			data->objs->color.g = 255.99 * (double)y / (data->settings.hsize - 1);
			data->objs->color.b = 0;
			printf("x: %d, y: %d, r: %d, g: %d, b: %d\n", x, y, data->objs->color.r, data->objs->color.g, data->objs->color.b);
			set_color(data, x, y, get_rgb(data->objs->color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (SUCESS);
}
