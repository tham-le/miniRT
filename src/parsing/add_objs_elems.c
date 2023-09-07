#include "../../inc/miniRT.h"

int add_a_sphere(t_objs **obj, char **elems)
{
    t_sphere *sphere;
    t_objs *obj2;

    sphere = (t_sphere *)malloc(sizeof(t_sphere));
    obj2 = (t_objs *)malloc(sizeof(t_objs));
    if(!elems[1] || !elems[2] || !elems[3] || elems[4])
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1])|| check_color(elems[3]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    sphere->point = get_position(elems[1]);
    sphere->diameter = ft_atod(elems[2]);
    sphere->color = get_color(elems[3]);
    obj2->type = SPHERE;
    obj2->polym = (t_sphere *)sphere;
    obj2->next = NULL;
    ft_lstaddback(obj, obj2);
    printf("obj: %d\n", (*obj)->type);
    *obj = (*obj)->next;
    return(0);
}

int add_a_cylindre(t_objs *obj, char **elems)
{
    t_cylindre *cylindre;
    t_objs *obj2;

    cylindre = (t_cylindre *)malloc(sizeof(t_cylindre));
    obj2 = (t_objs *)malloc(sizeof(t_objs));
    if(check_position(elems[1]) == -1 || check_position(elems[2]) || ft_atod(elems[3]) || ft_atod(elems[4]) || check_color(elems[5]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    cylindre->center = get_position(elems[1]);
    cylindre->norm = get_position(elems[2]);
    cylindre->diameter = ft_atod(elems[3]);
    cylindre->height = ft_atod(elems[4]);
    cylindre->color = get_color(elems[5]);
    obj2->type = CYLINDRE;
    obj2->polym = (t_cylindre *)cylindre;
    obj2->next = NULL;
    ft_lstaddback(&obj, obj2);
    obj = obj->next;
    return (0);
}

int add_a_plan(t_objs *obj, char **elems)
{
    t_plan *plan;
    t_objs *obj2;
    
    plan = (t_plan *)malloc(sizeof(t_plan));
    obj2 = (t_objs *)malloc(sizeof(t_objs));
    if(check_position(elems[1]) == -1 || check_position(elems[2]) || check_color(elems[3]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    plan->point = get_position(elems[1]);
    plan->orientation = get_position(elems[2]);
    plan->color = get_color(elems[3]);
    obj2->type = PLAN;
    obj2->polym = (t_plan *)plan;
    obj2->next = NULL;
    ft_lstaddback(&obj, obj2);
    obj = obj->next;
    return (0);
}