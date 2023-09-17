/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:13:03 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 18:33:44 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "miniRT.h"

int		ft_draw(t_data *data);
int		get_rgb(t_color color);
int		set_color(t_data *data, int x, int y, int color_int);

#endif
