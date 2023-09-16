/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:27:32 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/15 18:40:00 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	get_rgb(int a, int r, int g, int b)
{
    return(a << 24 | r << 16 | g << 8 | b);
}

int	get_color(t_color color)
{
    return(get_rgb(0, color.r, color.g, color.b));
}


