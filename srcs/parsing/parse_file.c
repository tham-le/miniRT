/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itchinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:04:44 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/20 19:09:01 by itchinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void set_infos(char *infos, t_objs *obj)
{
	char **tab_infos;

	tab_infos = ft_split(infos, ' ');
	obj->bmp_img->width = ft_atoi(tab_infos[0]);
	obj->bmp_img->height = ft_atoi(tab_infos[1]);
	obj->bmp_img->nb_colors = ft_atoi(tab_infos[2]);
	obj->bmp_img->char_per_pixel = ft_atoi(tab_infos[3]);
	ft_freearr(tab_infos);
}

void	readbump_img(t_objs *obj, t_data *data)
{
	(void)data;
	obj->mlx_bmp = mlx_init();
	obj->img_bmp = mlx_xpm_file_to_image(obj->mlx_bmp, obj->bump_img, &obj->bmp_width, &obj->bmp_height);
	if(!obj->img_bmp)
		return;
	obj->addr_bmp = mlx_get_data_addr(obj->img_bmp, &obj->bpp, &obj->line_length, &obj->endian);
	obj->win_bmp = mlx_new_window(obj->mlx_bmp, obj->bmp_width, obj->bmp_height, "bmp");
	mlx_put_image_to_window(obj->mlx_bmp, obj->win_bmp, obj->img_bmp, 0, 0);
}
