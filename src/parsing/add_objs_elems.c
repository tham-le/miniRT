#include "../../inc/miniRT.h"

int add_a_sphere(t_objs *obj, char **elems)
{
    t_sphere *sphere;
    t_objs *obj2;

    sphere = (t_sphere *)malloc(sizeof(t_sphere));
    obj2 = (t_objs *)malloc(sizeof(t_objs));
    if(get_position(elems[1]) == -1 || ft_atod(elems[2]) || get_color(elems[3]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    sphere->point = get_position(elems[1]);
    sphere->diameter = ft_atod(elems[2]);
    sphere->color = get_color(elems[3]);
    obj2->type = SPHERE;
    obj2->polym = (t_sphere *)sphere;
    obj2->next = NULL;
    return(0);
}

int add_a_clyindre(t_objs *obj, char **elems)
{
    t_cylindre *cylindre;

    cylindre = (t_cylindre *)malloc(sizeof(t_cylindre));
    if(get_position(elems[1]) == -1 || get_position(elems[2]) || ft_atod(elems[3]) || ft_atod(elems[4]) || get_color(elems[5]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    cylindre->center = get_position(elems[1]);
    cylindre->norm = get_position(elems[2]);
    cylindre->diameter = ft_atod(elems[3]);
    cylindre->height = ft_atod(elems[4]);
    cylindre->color = get_color(elems[5]);
    obj->type = CYLINDRE;
    obj->polym = (t_cylindre *)cylindre;
    obj->next = NULL;
    return (0);
}

int add_a_plan(t_objs *obj, char **elems)
{
    t_plan *plan;
    
    plan = (t_plan *)malloc(sizeof(t_plan));
    if(get_position(elems[1]) == -1 || get_position(elems[2]) || get_color(elems[3]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    plan->point = get_position(elems[1]);
    plan->orientation = get_position(elems[2]);
    plan->color = get_color(elems[3]);
    obj->type = PLAN;
    obj = (t_plan *)plan;
    obj->next = NULL;
    return (0);
}