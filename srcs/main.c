/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:08:38 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/04 20:13:09 by thi-le           ###   ########.fr       */
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
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr, W_W, W_H, fname);
	if (!(*data)->win_ptr)
		return (print_error("Error: mlx_new_window failed", 2));
	(*data)->img_ptr = mlx_new_image((*data)->mlx_ptr, W_W, W_H);
	if (!(*data)->img_ptr)
		return (print_error("Error: mlx_new_image failed", 3));
	(*data)->addr = mlx_get_data_addr((*data)->img_ptr, &(*data)->bits_per_pixel, \
	&(*data)->line_length, &(*data)->endian);
	if (!(*data)->addr)
		return (print_error("Error: mlx_get_data_addr failed", 4));
	return (SUCESS);
}

void	init_value(t_objs	*obj)
{
	obj->diffuse = 0.9;
	obj->highlighted = true;
	obj->reflective= 0.2;
	obj->shininess = 50;
	obj->specular = 0.8;
	identity_matrix(&obj->added_rots);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		state;
	t_objs	*obj;

	data = ft_calloc(sizeof(t_data), 2);
	if (ac != 2)
		return (free(data), ft_print_help());
	if (parsing(data, ac, av) != SUCESS)
		return (free(data), 1);
	print_struct(data);
	obj = data->objs;
	while (obj)
	{
		init_value(obj);
		obj = obj->next;
	}
	state = init_display(&data, av[1]);
	if (state != SUCESS)
		return (clean(data, state));
	hooks(data);
	camera_setting(data);
	calcul_transform(data);
	state = render(data);
	if (state != SUCESS)
		return (clean(data, state));
	mlx_loop(data->mlx_ptr);
	return (0);
}
