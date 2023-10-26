/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_objs_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:54:43 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/26 22:09:03 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathRT.h"
#include "miniRT.h"

void	push_light(t_light *obj, t_light **objs)
{
	t_light	*tmp;

	if (!(*objs))
		*objs = obj;
	else
	{
		tmp = *objs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
}

void	push_object(t_objs *obj, t_objs **objs)
{
	t_objs	*tmp;

	if (!(*objs))
		*objs = obj;
	else
	{
		tmp = *objs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
}

int	is_void(char c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/*int	parse_bmp(t_objs *obj)
{
	char	**names;
	char	*file_name;

	names = ft_split(obj->bump_img, ' ');
	file_name = names[0];
	if (ft_strcmp(ft_strrchr(file_name, '.'), ".xpm"))
		return (printf("Error: bumpmap file should end with \".xpm\"\n"), 1);
	if (access(obj->bump_img, R_OK) == -1)
		return (printf("Error: bumpmap file %s cannot be openned\n", 
		obj->bump_img), 1);
	return (0);
}*/
/*if (obj->bump_img && !parse_bmp(obj))
	{
		obj->bmp_img = ft_calloc(sizeof(t_bumpmap), 1);
		if (get_wh_bmp(obj))
			return (1);
		readbump_img(obj);
	}
	*/

/*int	get_wh_bmp(t_objs *obj)
{
	int		text_file;
	char	*line;
	char	*new_l;
	char	**infos_bmp;

	if (!(obj->bump_img))
		return (1);
	text_file = open(obj->bump_img, O_RDONLY, 0777);
	if (text_file == -1)
		return (printf("Error while openning bumpmap file %s\n", 
		obj->bump_img), 1);
	while (1)
	{
		line = get_next_line(text_file);
		if (ft_strchr(line, ','))
			break ;
	}
	new_l = ft_strtrim(line, "\"\n,");
	infos_bmp = ft_split(new_l, ' ');
	if (ft_tabsize(infos_bmp) != 4)
		return (printf("Error: a XPM file should have the width, 
		height, number of colors and number of char	per pixel in the 
		arguments\n"), 1);
	obj->bmp_img->bmp_width = ft_atoi(infos_bmp[0]);
	obj->bmp_img->bmp_height = ft_atoi(infos_bmp[1]);
	close(text_file);
	return (0);
}*/
