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

unsigned int stringToHex(const char *input) 
{
    unsigned int result = 0;
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        unsigned char byte = input[i];
        unsigned char upperNibble = (byte >> 4) & 0x0F;
        result = (result << 4) | upperNibble;
        unsigned char lowerNibble = byte & 0x0F;
        result = (result << 4) | lowerNibble;
    }

    return result;
}

int str_to_int(char *str)
{
    unsigned int hexa;
    int result = 0;
    int numNibbles = sizeof(unsigned int) * 2;
    int nibbleIndex = numNibbles - 1;

    hexa = stringToHex(str);
    while(nibbleIndex >= 0) 
    {
        int nibbleValue = (hexa >> (nibbleIndex * 4)) & 0xF;
        result <<= 4;
        result |= nibbleValue;
        nibbleIndex--;
    }

    return result;
}

int convert_to_color(char pixel, t_colors_bmp **pixel_lst)
{
    t_colors_bmp *ptr;

    ptr = (*pixel_lst);
    while(ptr)
    {
        //printf("c: %c\n", ptr->c);
        if(ptr->c == pixel)
            return(str_to_int(ptr->color));
        ptr = ptr->next;
    }
    //printf("zero\n");
    return(0);
}

int **ft_colortab(t_bumpmap *colors_bmp, int text_file, t_colors_bmp *pixel_lst)
{
    int **colortab;
    char *line;
    int i;
    int j;

    colortab = (int **)malloc(sizeof(int *) * (colors_bmp->height) + 1);
    i = 0;
    j = 0;
    printf("height: %d, width: %d\n", colors_bmp->height, colors_bmp->width);
    while(i < colors_bmp->height)
    {
        line = ft_split(get_next_line(text_file), '\"')[0];
        j = 0;
        colortab[i] = malloc(sizeof(int ) * (colors_bmp->width) + 1);
        while(j < colors_bmp->width)
        {
            colortab[i][j] = convert_to_color(line[j], &pixel_lst);
            printf("%dth color is  %d\n", j, colortab[i][j]);
            j++;
        }
        printf("une ligne\n");
        colortab[i][j] = 0;
        free(line);
        i++;
    }
    colortab[i][j] = 0;
    return(colortab);
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
    (void)tab_colors;

    if(!(obj->bump_img))
        return;	
    obj->bmp_img = ft_calloc(sizeof(t_bumpmap), 1);
    texture = obj->bump_img;
    text_file = open(texture, O_RDONLY, 0777);
    if(text_file == -1)
        return;
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
    //printf("nb colors: %d\n", obj->bmp_img->nb_colors);
    color_map = ft_calloc(sizeof(t_colors_bmp), 1);
    while(1)
    {
        line = get_next_line(text_file);
        color_map->c = line[1];
        new_l = ft_split(line, ' ');
        color_map->color = new_l[ft_tabsize(new_l) - 1];
        if(!line || strstr(line, "pixels"))
            break;
        else
        //printf("char: %c is color %s", color_map->c, color_map->color);
	    push_bump_color(color_map, &obj->colors_bmp);
        obj->colors_bmp = obj->colors_bmp->next;
    }
    tab_colors = ft_colortab(obj->bmp_img, text_file, color_map);
    ft_freearr(tab_infos);
    free(obj->bump_img);
}