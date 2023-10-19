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

int is_void(char c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int add_a_cone(t_data *data, char **elems)
{
	t_objs *obj;
	int ret;
	(void)ret;
	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (ft_tabsize(elems) < 6)
		return (free(obj), printf("Error: you should enter at least 5 infos for each cone\n"), 1);
	if (check_position(elems[1]) || check_vector(elems[2]) || check_color(elems[5]))
		return (free(obj), 1);
	if(check_float(elems[3]) || check_float(elems[4]))
		return (free(obj), printf("Error: the height/diameter arguments of a cone contains a character that is not a digit\n"), 1);
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
	//readbump_img(data->objs);
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
		return (free(obj), printf("Error: you should enter at least 5 infos for each sphere\n"),  1);
	if (check_position(elems[1]) || check_color(elems[3]))
		return (free(obj), 1);
	if(check_float(elems[2]))
		return (free(obj), printf("Error: the diameter argument of a sphere contains a character that is not a digit\n"), 1);
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
	// if (obj->bump_img)
	// 	readbump_img(data->objs);
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
		return (free(obj), printf("Error: you should enter at least 5 infos for each cylindre\n"),  1);
	if (check_position(elems[1]) || check_vector(elems[2]) || check_color(elems[5]))
		return (free(obj), 1);
	if(check_float(elems[3]) || check_float(elems[3]))
		return(free(obj), printf("Error: the height/diameter arguments of a cylinder contains a character that is not a digit\n"), 1);
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
	// readbump_img(data->objs);
	return (0);
}

int add_a_plan(t_data *data, char **elems)
{
	t_objs *obj;
	int ret;
	(void)ret;
	
	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	printf("plan\n");
	if (ft_tabsize(elems) < 4)
		return (free(obj), printf("Error: you should enter at least 5 infos for each plan\n"),  1);
	if (check_position(elems[1]) || check_vector(elems[2]) || check_color(elems[3]))
		return (free(obj), 1);
	add_options(obj, elems);
	obj->type = PLAN;
	obj->position = get_position(elems[1]);
	obj->vector = get_position(elems[2]);
	normalize_vec(&obj->vector);
	obj->color = get_color(elems[3]);
	obj->distance_to_origin = dot_product(&obj->vector, &obj->position);
	push_object(obj, &data->objs);
	// readbump_img(data->objs);
	return (0);
}

int add_a_triangle(t_data *data, char **elems)
{
	t_objs *obj;
	obj = ft_calloc(sizeof(t_objs), 1);
	init_obj_value(obj);
	if (ft_tabsize(elems) < 5)
		return (free(obj), printf("Error: you should enter at least 5 infos for each triangle\n"),  1);
	if (check_position(elems[1]) || check_position(elems[2]) || check_position(elems[3]) || check_color(elems[4]))
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
	// readbump_img(data->objs);
	return (0);
}
  
