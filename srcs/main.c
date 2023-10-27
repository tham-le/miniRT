/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:08:38 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 18:17:25 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*TO DO: TEXTURE MAPPING, BUM MAPPING, KEY HOOK TO MOVE CAMERA AND OBJECT*/

int	print_error(char *str, int state)
{
	if (str)
		ft_putendl(str);
	return (state);
}

static int	init_display(t_data **data, char *fname)
{
	(*data)->mlx_ptr = mlx_init();
	if (!(*data)->mlx_ptr)
		return (print_error("Error: mlx_init failed", 1));
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr, (*data)->width, \
		(*data)->height, fname);
	if (!(*data)->win_ptr)
		return (print_error("Error: mlx_new_window failed", 2));
	(*data)->img_ptr = mlx_new_image((*data)->mlx_ptr, (*data)->width, \
		(*data)->height);
	if (!(*data)->img_ptr)
		return (print_error("Error: mlx_new_image failed", 3));
	(*data)->addr = mlx_get_data_addr((*data)->img_ptr, &(*data)->bpp, \
	&(*data)->line_length, &(*data)->endian);
	if (!(*data)->addr)
		return (print_error("Error: mlx_get_data_addr failed", 4));
	return (SUCESS);
}

static void	init_data(t_data	*data)
{
	data->reflection_depth = 1;
	data->width = W_W;
	data->height = W_H;
	data->key = 0;
}

static void	camera_setting(t_data *data)
{
	double	half_view;
	double	h;
	double	w;

	h = data->height;
	w = data->width;
	half_view = tan((data->scene.camera.fov / 2.0f));
	data->scene.camera.aspect = w / h;
	if (data->scene.camera.aspect >= 1)
	{
		data->scene.camera.half_width = half_view;
		data->scene.camera.half_height = half_view / data->scene.camera.aspect;
	}
	else
	{
		data->scene.camera.half_width = half_view * data->scene.camera.aspect;
		data->scene.camera.half_height = half_view;
	}
	data->scene.camera.pixel_size = (data->scene.camera.half_width * 2) / w;
	data->scene.camera.phi = acos(data->scene.camera.vector.y);
	data->scene.camera.theta = atan(data->scene.camera.vector.z \
		/ data->scene.camera.vector.x);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		state;

	if (ac != 2)
		return (ft_print_help());
	data = ft_calloc(sizeof(t_data), 2);
	if (!data)
		return (print_error("Error: malloc failed", 1));
	init_data(data);
	if (parsing(data, ac, av) != SUCESS || !data->nb_lines)
		return (clean(data, 1));
	state = init_display(&data, av[1]);
	if (state != SUCESS)
		return (clean(data, state));
	camera_setting(data);
	calcul_transform(data);
	state = render(data);
	if (state != SUCESS)
		return (clean(data, state));
	hooks(data);
	clean(data, 5);
	return (0);
}
