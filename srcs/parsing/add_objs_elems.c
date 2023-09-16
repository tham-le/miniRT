#include "miniRT.h"


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
    if((c >= 7 && c <= 13) || c == 32)
        return(1);
    return(0);
}

int add_a_sphere(t_data *data, char **elems)
{
    t_objs *obj;
    int ret;
    (void)ret;

    obj = ft_calloc(sizeof(t_objs), 1);
    if(ft_tabsize(elems) != 4 || is_void(elems[3][0]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 6);
    if(check_position(elems[1]) || check_float(elems[2]) || check_color(elems[3]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 6);
    obj->type = SPHERE;
    obj->position = get_position(elems[1]);
    obj->diametre = ft_atod(elems[2]);
    if(obj->diametre < 0)
        obj->diametre = 0;
    obj->color = get_color(elems[3]);
    push_object(obj, &data->objs);
    return(0);
}

int add_a_cylindre(t_data *data, char **elems)
{
    t_objs *obj;
    int ret;
    (void)ret;
    obj = ft_calloc(sizeof(t_objs), 1);
    if(ft_tabsize(elems) != 6 || is_void(elems[5][0]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 6);
    if(check_position(elems[1]) || check_vector(elems[2]) || check_float(elems[3]) || check_float(elems[3]) || check_color(elems[5]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 6);
    obj->type = CYLINDRE;
    obj->position = get_position(elems[1]);
    obj->vector = get_position(elems[2]);
    obj->diametre = ft_atod(elems[3]);
    if(obj->diametre < 0)
        obj->diametre = 0;
    obj->height = ft_atod(elems[4]);
    obj->color = get_color(elems[5]);
    push_object(obj, &data->objs);
    return(0);
}

int add_a_plan(t_data *data, char **elems)
{
    t_objs *obj;
    int ret;
    (void)ret;
    
    obj = ft_calloc(sizeof(t_objs), 1);
    if(ft_tabsize(elems) != 4 || is_void(elems[3][0]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 6);
    if(check_position(elems[1]) || check_vector(elems[2]) || check_color(elems[3]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 6);
    obj->type = PLAN;
    obj->position = get_position(elems[1]);
    obj->vector = get_position(elems[2]);
    obj->color = get_color(elems[3]);
    push_object(obj, &data->objs);
    return(0);
}
