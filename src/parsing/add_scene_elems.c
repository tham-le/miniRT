#include "../../inc/miniRT.h"

int add_ambient(t_scene *sc, char **elems)
{
    if(atod(elems[1]) == -1 || get_color(elems[2]) == -1 || elems[3])
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    //si tout est bon on assigne les valeurs a la structure;
    sc->ambient.ratio = atod(elems[1]);
    sc->ambient.color = get_color(elems[2]);
    return(0);
}

int add_light(t_scene *sc, char **elems)
{
    if(get_position(elems[1]) == -1 || ft_atod(elems[2]) == -1 || get_color(elems) == -1 || elems[4])
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    sc->light.position = get_position(elems[1]);
    sc->light.ratio = atod(elems[2]);
    sc->light.color = get_color(elems[3]);
}

int add_camera(t_scene *sc, char **elems)
{
    if(get_position(elems[1]) == -1 || get_position(elems[2]) == -1 || !ft_atoi(elems[3]) || elems[4])
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    sc->camera.position = get_position(elems[1]);
    sc->camera.vector = get_position(elems[2]);
    sc->camera.fov = ft_atoi(elems[3]);
}