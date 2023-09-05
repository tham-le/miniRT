#include "../../inc/miniRT.h"

int add_a_sphere(t_objs *obj, char **elems)
{
    t_sphere *sphere;

    if(get_position(elems[1]) == -1 || ft_atod(elems[2]) || get_color(elems[3]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    obj->type = SPHERE;
    obj = (t_sphere *)sphere;
    return(0);
}

int add_a_clyindre(t_objs *obj, char **elems)
{
    t_cylindre *cylindre;

    if(get_position(elems[1]) == -1 || get_position(elems[2]) || ft_atod(elems[3]) || ft_atod(elems[4]) || get_color(elems[5]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    obj->type = CYLINDRE;
    obj = (t_cylindre *)cylindre;
}

int add_a_plan(t_objs *obj, char **elems)
{
    t_plan *plan;
    
    if(get_position(elems[1]) == -1 || get_position(elems[2]) || get_color(elems[3]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    obj->type = PLAN;
    obj = (t_plan *)plan;
}