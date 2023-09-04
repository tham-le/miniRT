#include "../../inc/miniRT.h"

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

int add_to_list(t_scene *sc, t_objs *obj, int type, char **elems)
{
}