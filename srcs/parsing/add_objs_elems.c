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

int add_a_sphere(t_data *data, char **elems)
{
    t_objs *obj;
    int ret;
    (void)ret;

    obj = ft_calloc(sizeof(t_objs), 1);
    if(!elems[1] || !elems[2] || !elems[3] || elems[4])
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1])|| check_color(elems[3]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    obj->type = SPHERE;
    obj->position = get_position(elems[1]);
    obj->diametre = ft_atod(elems[2]);
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
    if(check_position(elems[1]) == -1 || check_position(elems[2]) || ft_atod(elems[3]) || ft_atod(elems[4]) || check_color(elems[5]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    obj->type = CYLINDRE;
    obj->position = get_position(elems[1]);
    obj->vector = get_position(elems[2]);
    obj->diametre = ft_atod(elems[3]);
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
    if(check_position(elems[1]) == -1 || check_position(elems[2]) || check_color(elems[3]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    obj->type = PLAN;
    obj->position = get_position(elems[1]);
    obj->vector = get_position(elems[2]);
    obj->color = get_color(elems[5]);
    push_object(obj, &data->objs);
    return(0);
}
