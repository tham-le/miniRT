#include "miniRT.h"


// int add_ambient(t_data *data, char **elems)
// {
//     t_objs *obj;

//     obj = ft_calloc(sizeof(t_objs), 1);
//     if(!elems[1] || !elems[2] || elems[3])
//         return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
//     if(check_position(elems[1]) == -1 || check_position(elems[2]))
//         return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
//     obj->type = AMBIENT;
//     obj->ratio = ft_atod(elems[1]);
//     obj->color = get_color(elems[2]);
//     push_object(obj, &data->objs);
//     return(0);
// }

// int add_light(t_data *data, char **elems)
// {
//     t_objs *obj;

//     obj = ft_calloc(sizeof(t_objs), 1);
//     if(!elems[1] || !elems[2] || !elems[3] || elems[4])
//         return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
//     if(check_position(elems[1]) == -1 || ft_atod(elems[2]) == -1 || check_color(elems[3]) == -1 || elems[4])
//         return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
//     obj->type = LIGHT;
//     obj->position = get_position(elems[1]);
//     obj->ratio = ft_atod(elems[2]);
//     obj->color = get_color(elems[3]);
//     push_object(obj, &data->objs);
//     return(0);
// }

int add_camera(t_data *data, char **elems)
{
    t_camera *camera;

    camera = ft_calloc(sizeof(t_camera), 1);
    if(!elems[1] || !elems[2] || !elems[3] || elems[4])
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    if(check_position(elems[1]) == -1 || check_position(elems[2]) || !ft_atoi(elems[3]))
        return(write(STDERR_FILENO, ERR_INFOS_ELEM, 29), 1);
    camera->position = get_position(elems[1]);
    camera->vector = get_position(elems[2]);
    camera->fov = ft_atoi(elems[3]);
    data->scene->camera = camera;
    return(0);
}
