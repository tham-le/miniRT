/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:12:01 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 21:22:07 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

int	draw(t_data *data)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;

	y = 0;
	while (y < data->settings.hsize)
	{
		if (y % 100 == 0)
			printf("remaining: %f\n", data->settings.hsize - y);
		x = 0;
		while (x < data->settings.vsize)
		{
			ray  = ray_to_pixel(data, x, y);
			color = intersect_color(data, &ray);
			set_color(data, x, y, get_rgb(ray.color));
			x++;
		}
		y++;
	}
	printf("remaining: %f\n", data->settings.hsize - y);
	printf("done\n");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (SUCESS);
}
