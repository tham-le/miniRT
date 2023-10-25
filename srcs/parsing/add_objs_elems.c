#include "mathRT.h"
#include "miniRT.h"

int get_wh_bmp(t_objs **obj)
{
	int		text_file;
	char *line;
	char *new_l;
	char **infos_bmp;

	if (!((*obj)->bump_img))
		return (1);	
	text_file = open((*obj)->bump_img, O_RDONLY, 0777);
	if (text_file == -1)
	{
		printf("Error while openning bumpmap file %s\n", (*obj)->bump_img);
		return (1);
	}
	while (1)
	{
		line = get_next_line(text_file);
		if (ft_strchr(line, ','))
			break ;
	}
	new_l = ft_strtrim(line, "\"\n,");
	infos_bmp = ft_split(new_l, ' ');
	if(ft_tabsize(infos_bmp) != 4)
	{
		printf("Error: a XPM file should have the width, height, number of colors and number of char per pixel in the arguments\n");
		return (1);
	}
	(*obj)->bmp_width = ft_atoi(infos_bmp[0]);
	(*obj)->bmp_height = ft_atoi(infos_bmp[1]);
	printf("w: %d h: %d\n",(*obj)->bmp_width, (*obj)->bmp_height);
	return(0);
}

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

int is_void(char c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int parse_bmp(t_objs *obj)
{
	char **names;
	char *file_name;

	names = ft_split(obj->bump_img, ' ');
	file_name = names[0];
	if(ft_strcmp(ft_strrchr(file_name, '.'), ".xpm"))
		return(printf("Error: bumpmap file should end with \".xpm\"\n"), 1);
	if(access(obj->bump_img, R_OK) == -1)
		return(printf("Error: bumpmap file %s cannot be openned\n", obj->bump_img), 1);
	return(0);
}

int add_a_cone(t_data *data, char **elems)
{
	t_objs *obj;
	int ret;
	(void)ret;
	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (ft_tabsize(elems) < 6)
		return (free(obj), printf("Error: line %d: you should enter at least 5 infos for each cone\n", data->nb_lines), 1);
	if (check_position(elems[1], data) || check_vector(elems[2], data) || check_color(elems[5], data))
		return (free(obj), 1);
	if(check_float(elems[3]) || check_float(elems[4]))
		return (free(obj), printf("Error: line %d: the height/diameter arguments of a cone contains a character that is not a digit\n", data->nb_lines), 1);
	add_options(obj, elems);
	obj->type = CONE;
	obj->position = get_position(elems[1]);
	obj->vector = get_position(elems[2]);
	obj->diametre = ft_atod(elems[3]);
	if (obj->diametre < 0)
		obj->diametre = 0;
	obj->radius = obj->diametre / 2;
	obj->height = ft_atod(elems[4]);
	obj->color = get_color(elems[5]);
	push_object(obj, &data->objs);
	if (obj->bump_img && !parse_bmp(obj))
	{
		if(get_wh_bmp(&data->objs))
			return(1);
		readbump_img(data->objs);
	}
	return (0);
}

int add_a_sphere(t_data *data, char **elems)
{
	t_objs *obj;
	int ret;
	(void)ret;

	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (ft_tabsize(elems) < 4)
		return (free(obj), printf("Error: line %d: you should enter at least 5 infos for each sphere\n", data->nb_lines),  1);
	if (check_position(elems[1], data) || check_color(elems[3], data))
		return (free(obj), 1);
	if(check_float(elems[2]))
		return (free(obj), printf("Error: line %d: the diameter argument of a sphere contains a character that is not a digit\n", data->nb_lines), 1);
	add_options(obj, elems);
	obj->type = SPHERE;
	obj->position = get_position(elems[1]);
	obj->diametre = ft_atod(elems[2]);
	if (obj->diametre < 0)
		return (free(obj), ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
	obj->radius = obj->diametre / 2;
	obj->squared_radius = obj->radius * obj->radius;
	obj->color = get_color(elems[3]);
	push_object(obj, &data->objs);
	if (obj->bump_img && !parse_bmp(obj))
	{
		if(get_wh_bmp(&data->objs))
			return(1);
		readbump_img(data->objs);
	}
	return (0);
}

int add_a_cylindre(t_data *data, char **elems)
{
	t_objs *obj;
	int ret;
	(void)ret;
	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (ft_tabsize(elems) < 6)
		return (free(obj), printf("Error: line %d: you should enter at least 5 infos for each cylindre\n", data->nb_lines),  1);
	if (check_position(elems[1], data) || check_vector(elems[2], data) || check_color(elems[5], data))
		return (free(obj), 1);
	if(check_float(elems[3]) || check_float(elems[3]))
		return(free(obj), printf("Error: line %d: the height/diameter arguments of a cylinder contains a character that is not a digit\n", data->nb_lines), 1);
	add_options(obj, elems);
	obj->type = CYLINDER;
	obj->position = get_position(elems[1]);
	obj->vector = get_position(elems[2]);
	obj->diametre = ft_atod(elems[3]);
	if (obj->diametre < 0)
		obj->diametre = 0;
	obj->radius = obj->diametre / 2;
	obj->height = ft_atod(elems[4]);
	obj->color = get_color(elems[5]);
	push_object(obj, &data->objs);
	if (obj->bump_img && !parse_bmp(obj))
	{
		if(get_wh_bmp(&data->objs))
			return(1);
		readbump_img(data->objs);
	}
	return (0);
}

int add_a_plan(t_data *data, char **elems)
{
	t_objs *obj;
	int ret;
	(void)ret;
	
	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (ft_tabsize(elems) < 4)
		return (free(obj), printf("Error: line %d: you should enter at least 5 infos for each plan\n", data->nb_lines),  1);
	if (check_position(elems[1], data) || check_vector(elems[2], data) || check_color(elems[3], data))
		return (free(obj), 1);
	add_options(obj, elems);
	obj->type = PLAN;
	obj->position = get_position(elems[1]);
	obj->vector = get_position(elems[2]);
	normalize_vec(&obj->vector);
	obj->color = get_color(elems[3]);
	obj->distance_to_origin = dot_product(&obj->vector, &obj->position);
	push_object(obj, &data->objs);
	if (obj->bump_img && !parse_bmp(obj))
	{
		if(get_wh_bmp(&data->objs))
			return(1);
		readbump_img(data->objs);
	}
	return (0);
}

int add_a_triangle(t_data *data, char **elems)
{
	t_objs *obj;
	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (ft_tabsize(elems) < 5)
		return (free(obj), printf("Error: line %d: you should enter at least 5 infos for each triangle\n", data->nb_lines),  1);
	if (check_position(elems[1], data) || check_position(elems[2], data) || check_position(elems[3], data) || check_color(elems[4], data))
		return (free(obj), 1);
	add_options(obj, elems);
	obj->type = TRIANGLE;
	obj->vertex[0] = get_position(elems[1]);
	obj->vertex[1] = get_position(elems[2]);
	obj->vertex[2] = get_position(elems[3]);
	sub_vec(&obj->edge[1], &obj->vertex[1], &obj->vertex[0]);
	sub_vec(&obj->edge[2], &obj->vertex[2], &obj->vertex[0]);
	cross_product(&obj->normal, &obj->edge[1], &obj->edge[2]);
	normalize_vec(&obj->normal);
	obj->normal.w = 0;
	obj->color = get_color(elems[4]);
	push_object(obj, &data->objs);
	if (obj->bump_img && !parse_bmp(obj))
	{
		if(get_wh_bmp(&data->objs))
			return(1);
		readbump_img(data->objs);
	}
	return (0);
}
  
