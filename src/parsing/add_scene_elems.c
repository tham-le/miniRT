#include "../../inc/miniRT.h"

int add_ambient(t_scene *sc, char **elems)
{
    if(!elems[1] || !elems[2] || !elems[3] || elems[4])
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1]) == -1 || check_position(elems[2]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    sc->ambient.ratio = ft_atod(elems[1]);
    sc->ambient.color = get_color(elems[2]);
    return(0);
}

int add_light(t_scene *sc, char **elems)
{
    if(check_position(elems[1]) == -1 || ft_atod(elems[2]) == -1 || check_color(elems[3]) == -1 || elems[4])
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    sc->light.position = get_position(elems[1]);
    sc->light.ratio = ft_atod(elems[2]);
    sc->light.color = get_color(elems[3]);
    return(0);
}

int add_camera(t_scene *sc, char **elems)
{
    if(!elems[1] || !elems[2] || !elems[3] || elems[4])
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1]) == -1 || check_position(elems[2]) || !ft_atoi(elems[3]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    sc->camera.fov = ft_atoi(elems[1]);
    sc->camera.position = get_position(elems[2]);
    sc->camera.vector = get_position(elems[3]);
    return(0);
}