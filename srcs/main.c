/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:08:38 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:22:33 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	print_error(char *str, int state)
{
	if (str)
		ft_putendl(str);
	return (state);
}

int	init_display(t_data **data, char *fname)
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

int	main(int ac, char **av)
{
	t_data	*data;
	int		state;

	if (ac != 2)
		return (ft_print_help());
	data = ft_calloc(sizeof(t_data), 2);
	data->reflection_depth = 1;
	data->width = W_W;
	data->height = W_H;
	if (parsing(data, ac, av) != SUCESS || !data->nb_lines)
		return (clean(data, 1));
	state = init_display(&data, av[1]);
	if (state != SUCESS)
		return (clean(data, state));
	hooks(data);
	camera_setting(data);
	calcul_transform(data);
	state = render(data);
	if (state != SUCESS)
		return (clean(data, state));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_loop(data->mlx_ptr);
	clean(data, 5);
	return (0);
}
