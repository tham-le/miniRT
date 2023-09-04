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
    void *element;

    if(type == AMBIENT)
    {
        //checker qu'on a bien le ratio en deuxieme argument
        //checker qu'on a bien une couleur en troisieme argument
        //checker que le troisieme argument n'existe pas (car ambiant n'a que 2 infos)
        if(atod(elems[1]) == -1 || get_color(elems[2]) == -1 || elems[3])
            return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
        //si tout est bon on assigne les valeurs a la structure;
        sc->ambient.ratio = atod(elems[1]);
        sc->ambient.color = get_color(elems[2]);
        return(0);
    }
    else if(type == LIGHT)
    {
        if(get_position(elems[1]) == -1 || atod(elems[2]) == -1 || get_color(elems) == -1 || elems[4])
            return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
        sc->light.position = get_position(elems[1]);
        sc->light.ratio = atod(elems[2]);
        sc->light.color = get_color(elems[3]);
        return(0);
    }
    else if(type == CAMERA)
    {
        if(get_position(elems[1]) == -1 || get_)
    }
}