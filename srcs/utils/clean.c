/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:18:57 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/10 20:03:15 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "structs.h"

/* clean code
** state 1: mlx_init failed ->
** state 2: mlx_new_window failed -> destroy mlx_ptr
** state 3: mlx_new_image failed -> destroy window, mlx_ptr 
** state 4: mlx_get_data_addr failed -> destroy image, window, mlx_ptr
** state 5: ft_parse_file failed -> destroy image, window, mlx_ptr
** 
 */
int		clean(t_data *data, int state)
{
	// if (state > 4)
	// 	free(data)
	if (state > 3)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (state > 2)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (state > 1)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	return (1);
}
