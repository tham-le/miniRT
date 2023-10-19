#include "miniRT.h"

int	**ft_colortab(t_bumpmap *colors_bmp, int text_file, t_colors_bmp *pixel_lst)
{
	char	*line;
	int		**colortab;
	int		i;
	int		j;

	colortab = (int **)malloc(sizeof(int *) * (colors_bmp->height) + 1);
	if (!colortab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < colors_bmp->height)
	{
		line = ft_split(get_next_line(text_file), '\"')[0];
		j = 0;
		colortab[i] = malloc(sizeof(int ) * 2 * (colors_bmp->width) + 1);
		if (!colortab[i])
			return (NULL);
		while (j < colors_bmp->width)
		{
			colortab[i][j] = convert_to_color(line[j], &pixel_lst);
			j++;
		}
		printf("ligne %d done\n", i);
		colortab[i][j] = 0;
		free(line);
		i++;
	}
	colortab[i] = 0;
	return (colortab);
}

void readbump_img(t_objs *obj)
{
	char *texture;
	int text_file;
	char **new_l;
	char *infos;
	char **tab_infos;
	t_colors_bmp *color_map;
	char *line = NULL;
	int **tab_colors;

	if (!(obj->bump_img))
		return ;	
	obj->bmp_img = ft_calloc(sizeof(t_bumpmap), 1);
	texture = obj->bump_img;
	text_file = open(texture, O_RDONLY, 0777);
	if (text_file == -1)
		return ;
	while (1)
	{
		line = get_next_line(text_file);
		if (ft_strchr(line, ','))
			break ;
	}
	infos = ft_substr(line, 1, ft_strlen(line) - 4);
	tab_infos = ft_split(infos, ' ');
	obj->bmp_img->width = ft_atoi(tab_infos[0]);
	obj->bmp_img->height = ft_atoi(tab_infos[1]);
	obj->bmp_img->nb_colors = ft_atoi(tab_infos[2]);
	obj->bmp_img->char_per_pixel = ft_atoi(tab_infos[3]);
	//printf("nb colors: %d\n", obj->bmp_img->nb_colors);
	color_map = ft_calloc(sizeof(t_colors_bmp), 1);
	while (1)
	{
		line = get_next_line(text_file);
		color_map->c = line[1];
		new_l = ft_split(line, ' ');
		color_map->color = new_l[ft_tabsize(new_l) - 1];
		if (!line || strstr(line, "pixels"))
			break ;
		else
			//printf("char: %c is color %s", color_map->c, color_map->color);
			push_bump_color(color_map, &obj->colors_bmp);
		obj->colors_bmp = obj->colors_bmp->next;
	}
	tab_colors = ft_colortab(obj->bmp_img, text_file, color_map);
	obj->tab_bmp = tab_colors;
	ft_freearr_int(tab_colors);
	ft_freearr(tab_infos);
	free(obj->bump_img);
}
