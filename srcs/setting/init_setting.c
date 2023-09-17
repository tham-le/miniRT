/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:38:12 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 18:47:53 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "setting.h"

void	init_setting(t_data *data)
{
	data->settings.hsize = W_WIDTH;
	data->settings.vsize = W_HEIGHT;

}
