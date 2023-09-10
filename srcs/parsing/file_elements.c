#include "miniRT.h"

int first_element(char *elem)
{
    if(!ft_strncmp(elem, "A", ft_strlen(elem)))
        return (AMBIENT);
    else if(!ft_strncmp(elem, "L", ft_strlen(elem)))
        return (LIGHT);
    else if(!ft_strncmp(elem, "C", ft_strlen(elem)))
        return (CAMERA);
    else if(!ft_strncmp(elem, "sp", ft_strlen(elem)))
        return (SPHERE);
    else if(!ft_strncmp(elem, "cy", ft_strlen(elem)))
        return (CYLINDRE);
    else if(!ft_strncmp(elem, "pl", ft_strlen(elem)))
        return (PLAN);
    return(-1);
}

int add_to_struct(t_scene *sc, t_objs *obj, int type, char *line)
{
    char **elems;
    int ret;

    elems = ft_split(line, ' ');
    ret = 0;
    if(!elems)
        return(1);
    if(type == SPHERE)
        ret = add_a_sphere(&obj, elems);
    else if(type == CYLINDRE)
        ret = add_a_cylindre(obj, elems);
    else if(type == PLAN)
        ret = add_a_plan(obj, elems);
    else if(type == AMBIENT)
        ret = add_ambient(sc, elems);
    else if(type == LIGHT)
        ret = add_light(sc, elems);
    else if(type == CAMERA)
        ret = add_camera(sc, elems);
    return(ret);
}
