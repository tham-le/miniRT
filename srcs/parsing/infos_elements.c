#include "miniRT.h"


int check_position(char *elems)
{
    char **position;
    int ret;
    (void)ret;

    position = ft_split(elems, ',');
    if(!position)
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 30), 1);
    return(0);
}

t_vector get_position(char *elems)
{
    char **position;
    t_vector vec_pos;

    position = ft_split(elems, ',');
    vec_pos.x = ft_atod(position[0]);
    vec_pos.y = ft_atod(position[1]);
    vec_pos.z = ft_atod(position[2]);
    return(vec_pos);
}

int check_color(char *elems)
{
    char **color;
    int ret;
    (void)ret;

    color = ft_split(elems, ',');
    if(!color)
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 30), 1);
    return(0);
}

t_color get_color(char *elems)
{
    char **color;
    t_color vec_col;

    color = ft_split(elems, ',');
    vec_col.r = ft_atoi(color[0]);
    vec_col.g = ft_atoi(color[1]);
    vec_col.b = ft_atoi(color[2]);
    return(vec_col);
}
