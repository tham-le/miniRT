/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:34:39 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 17:49:22 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_all_ok(t_data *data)
{
	clean(data, 6);
	free_all(data);
	exit(0);
}

int	red_cross(t_data *data)
{
	free_all_ok(data);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		free_all_ok(data);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data);
	//mlx_hook(data->win, ButtonPress, ButtonPressMask, &mouse_press, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &red_cross, data);
}
