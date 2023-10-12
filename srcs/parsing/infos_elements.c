#include "miniRT.h"

char *before_dot(char *elems, int *dot)
{
    int i;

    i = 0;
    while(elems[i] && elems[i] != '.')
    {
        i++;
        (*dot)++;
    }
    return(ft_substr(elems, 0, *dot));
}

char *after_dot(char *elems, int *dot)
{
    int i;

    i = *dot + 1;
    while(elems[i])
        i++;
    return(ft_substr(elems, *dot + 1, ft_strlen(elems)));
}

int nb_dots(char *elems)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(elems[i])
    {
        if(elems[i] == '.')
            count++;
        i++;
    }
    return(count);
}

int only_digits(char *str)
{
    int i;

    i = 0;
    while(str[i] && str[i] != '\n')
    {
        if(!ft_isdigit(str[i]))
        {
            if(str[i] == '-' && i == 0)
            {
                i++;
                continue;
            }
            return(1);
        }
        i++;
    }
    return(0);
}

int check_float(char *elems)
{
    char *bef_dot;
    char *aft_dot;
    int dot;

    dot = 0;
    bef_dot = before_dot(elems, &dot);
    aft_dot = after_dot(elems, &dot);
    if(nb_dots(elems) > 1)
        return (1);
    if(only_digits(bef_dot) || only_digits(aft_dot))
        return(free(bef_dot), free(aft_dot), 1);
    free(bef_dot);
    free(aft_dot);
    return(0);
}

int check_position(char *elems)
{
    char **position;

    int ret;
    (void)ret;

    position = ft_split(elems, ',');
    if(!position || !position[2])
        return(1);
    if(check_float(position[0]) || check_float(position[1]) || check_float(position[2]))
        return(ft_freearr(position), 1);
    ft_freearr(position);
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
    vec_pos.w = 1;
    ft_freearr(position);
    return(vec_pos);
}

int check_color(char *elems)
{
    char **color;
    int ret;
    int col_r;
    int col_g;
    int col_b;
    (void)ret;

    color = ft_split(elems, ',');
    col_r = ft_atod(color[0]);
    col_g = ft_atod(color[1]);
    col_b = ft_atod(color[2]);
    if(!color)
        return(ret = write(STDERR_FILENO, ERR_INFOS_ELEM, 30), 1);
    if(only_digits(color[0]) || only_digits(color[1]) || only_digits(color[2]))
        return(ft_freearr(color), 1);
    if(col_r < 0 || col_r > 255 || col_g < 0 || col_g > 255 || col_b < 0 || col_b > 255)
        return(ft_freearr(color), 1);
    ft_freearr(color);
    return(0);
}

t_color get_color(char *elems)
{
    char **color;
    t_color vec_col;

    color = ft_split(elems, ',');
    vec_col.r = ft_atod(color[0]) / 255.f;
    vec_col.g = ft_atod(color[1]) / 255.f;
    vec_col.b = ft_atod(color[2]) / 255.f;
    ft_freearr(color);
    return(vec_col);
}
