#include "miniRT.h"

int add_ambient(t_data *data, char **elems)
{
    t_ambient ambient;
    int ret;
    (void)ret;

    ft_bzero(&ambient, sizeof(t_ambient));
    if(!elems[1] || !elems[2] || elems[3])
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_color(elems[2]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    ambient.ratio = ft_atod(elems[1]);
    ambient.color = get_color(elems[2]);
    data->scene.ambient = ambient;
    return(0);
}

int add_light(t_data *data, char **elems)
{
    t_light light;
    int ret;
    (void)ret;

    ft_bzero(&light, sizeof(t_light));
    if(!elems[1] || !elems[2] || !elems[3] || elems[4])
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1]) == -1 || ft_atod(elems[2]) == -1 || check_color(elems[3]) == -1 || elems[4])
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    light.position = get_position(elems[1]);
    light.ratio = ft_atod(elems[2]);
    light.color = get_color(elems[3]);
    data->scene.light = light;
    return(0);
}

int add_camera(t_data *data, char **elems)
{
    t_camera camera;
    int ret;
    (void)ret;

    ft_bzero(&camera, sizeof(t_camera));
    if(!elems[1] || !elems[2] || !elems[3] || elems[4])
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1]) == -1 || check_position(elems[2]) || !ft_atoi(elems[3]))
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    camera.position = get_position(elems[1]);
    camera.vector = get_position(elems[2]);
    camera.fov = ft_atoi(elems[3]);
    data->scene.camera = camera;
    return(0);
}
