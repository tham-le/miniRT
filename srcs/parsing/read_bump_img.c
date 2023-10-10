#include "miniRT.h"

void	push_bump_color(t_colors_bmp *obj, t_colors_bmp **objs)
{
	t_colors_bmp	*tmp;

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

void readbump_img(t_objs *obj)
{
    char *texture;
    int text_file;
    char **new_l;
    char *infos;
    char **tab_infos;
    t_colors_bmp *color_map;
    char *line = NULL;

    if(!(obj->bump_img))
        return;	
    obj->bmp_img = ft_calloc(sizeof(t_bumpmap), 1);
    texture = obj->bump_img;
    text_file = open(texture, O_RDONLY, 0777);
    if(text_file == -1)
    {
        // write(STDERR_FILENO, "Cannot read bump file\n", 22);
        return;
    }
    while(1)
    {
        line = get_next_line(text_file);
        if(ft_strchr(line, ','))
            break;
    }
    infos = ft_substr(line, 1, ft_strlen(line) - 4);
    tab_infos = ft_split(infos, ' ');
    obj->bmp_img->width = ft_atoi(tab_infos[0]);
    obj->bmp_img->height = ft_atoi(tab_infos[1]);
    obj->bmp_img->nb_colors = ft_atoi(tab_infos[2]);
    obj->bmp_img->char_per_pixel = ft_atoi(tab_infos[3]);
    printf("nb colors: %d\n", obj->bmp_img->nb_colors);
    color_map = ft_calloc(sizeof(t_colors_bmp), 1);
    while(1)
    {
        line = get_next_line(text_file);
        color_map->c = line[1];
        new_l = ft_split(line, ' ');
        color_map->color = new_l[ft_tabsize(new_l) - 1];
        if(!line || strstr(line, "pixels"))
            break;
        printf("char: %c is color %s", color_map->c, color_map->color);
	    push_bump_color(color_map, &obj->colors_bmp);
        obj->colors_bmp = obj->colors_bmp->next;
    }
    ft_freearr(tab_infos);
    free(obj->bump_img);
}