/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:34:39 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 21:07:35 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "structs.h"
#include "miniRT.h"

int	red_cross(t_data *data)
{
	clean(data, 5);
	printf("BYE\n");
	return (0);
}

// int	key_press(int key, t_data *data)
// {
// 	if (key == XK_Escape)
// 	{
// 		printf("Exit\n");
// 		clean(data, 5);
// 	}
// 	return (0);
// }

// void	hooks(t_data *data)
// {
// 	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data);
// 	mlx_hook(data->win_ptr, DestroyNotify, 0, &red_cross, data);
// 	mlx_loop(data->mlx_ptr);
// }
int	key_press(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		printf("BYE\n");
		clean(data, 5);
	}
	if (key == XK_w || key == XK_s || key == XK_a \
	|| key == XK_d || \
		key == XK_q || key == XK_e)
		move_camera(key, data);
	if (key == XK_Up || key == XK_Down || key == XK_Left \
	|| key == XK_Right)
		move_camera2(key, data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (data->key == 1 && (key == XK_Up || key == XK_Down \
	|| key == XK_Left || key == XK_Right || key == XK_w \
	|| key == XK_s || key == XK_a || key == XK_d \
	|| key == XK_q || key == XK_e))
	{
		calcul_transform(data);
		render(data);
		data->key = 0;
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, \
	KeyPressMask, &key_press, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, \
	&key_release, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &red_cross, data);
	mlx_loop(data->mlx_ptr);
}
