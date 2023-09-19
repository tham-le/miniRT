/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:39:35 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/18 23:55:53 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	camera_transform(t_camera camera)
{
	t_vector	origin;

	origin = (t_vector){camera.position.x, camera.position.y, camera.position.z};
	camera.vector = vec_norm(camera.vector);


}


void	transform(t_data *data)
{
	camera_transform(data->scene.camera);
}
