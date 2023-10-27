/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:04:44 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/27 22:53:29 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "miniRT.h"
#include <stdio.h>

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


void	readbump_img(t_objs *obj)
{
	obj->bmp_img->mlx_bmp = mlx_init();
	obj->bmp_img->img_bmp = mlx_xpm_file_to_image(obj->bmp_img->mlx_bmp,
	 obj->bump_img, &obj->bmp_img->bmp_width, &obj->bmp_img->bmp_height);
	if(!obj->bmp_img->img_bmp)
		return;
	printf("bmp_width = %d\n", obj->bmp_img->bmp_width);
	printf("obj->bmp_img->img_bmp = %p\n", obj->bmp_img->img_bmp);
	printf("obj->bmp_img->img_bmp = %s\n", obj->bmp_img->img_bmp);
	obj->bmp_img->addr_bmp = mlx_get_data_addr(obj->bmp_img->img_bmp,
	 &obj->bmp_img->bpp, &obj->bmp_img->line_length, &obj->bmp_img->endian);;
	printf("obj->bmp_img->addr_bmp = %p\n", obj->bmp_img->addr_bmp);
	printf("obj->bmp_img->line_length = %d\n", obj->bmp_img->line_length);
	printf("obj->bmp_img->bpp = %d\n", obj->bmp_img->bpp);
	obj->bmp_img->win_bmp = mlx_new_window(obj->bmp_img->mlx_bmp,
	 obj->bmp_img->bmp_width, obj->bmp_img->bmp_height, "bmp");
	mlx_put_image_to_window(obj->bmp_img->mlx_bmp, obj->
	bmp_img->win_bmp, obj->bmp_img->img_bmp, 0, 0);
}
*/
