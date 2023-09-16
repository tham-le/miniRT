/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:08:38 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/16 16:16:19 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	print_error(char *str, int state)
{
	if (str)
		ft_putendl(str);
	return (state);
}

// int	clean(t_data *data, int state)
// {
// 	// if (state > 4)
// 	// 	free(data)
// 	if (state > 3)
// 		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
// 	if (state > 2)
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	if (state > 1)
// 	{
// 		mlx_destroy_display(data->mlx_ptr);
// 		free(data->mlx_ptr);
// 	}
// 	return (1);
// }

int	init_display(t_data *data, char *fname)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (print_error("Error: mlx_init failed", 1));
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, fname);
	if (!data->win_ptr)
		return (
		print_error("Error: mlx_new_window failed", 2));
	data->img_ptr = mlx_new_image(data->mlx_ptr,W_WIDTH, W_HEIGHT);
	if (!data->img_ptr)
		return (
		print_error("Error: mlx_new_image failed", 3));
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	if (!data->addr)
		return (
		print_error("Error: mlx_get_data_addr failed", 4));
	return (SUCESS);
}

int main(int ac, char **av)
{
	t_data	*data;
	//int		state;

	data = ft_calloc(sizeof(t_data), 1);
	if (ac != 2)
		return (ft_print_help());
	if (parsing(data, ac, av) != SUCESS)
		return (1);
	// state = init_display(&data, av[1]);
	// if (state != SUCESS)
	// 	return (clean(&data, state));
	// state = draw(&data);
	// if (state != SUCESS)
	// 	return (clean(&data, state));
	// hookloop(&data);

    return (0);
}
