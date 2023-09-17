#include "miniRT.h"

int check_ratio(char *flt)
{
    float converted_num;

    if(check_float(flt))
        return(1);
    converted_num = ft_atod(flt);
    if(converted_num < 0 || converted_num > 1)
        return(1);
    return(0);
}

int check_vector(char *vect)
{
    char **position;
    int ret;
    int vec_x;
    int vec_y;
    int vec_z;
    (void)ret;

    if(check_position(vect))
        return(1);
    position = ft_split(vect, ',');
    if(!position)
        return(1);
    vec_x = ft_atod(position[0]);
    vec_y = ft_atod(position[1]);
    vec_z = ft_atod(position[2]);
    if(vec_x < -1 || vec_x > 1 || vec_y < -1 || vec_y > 1 || vec_z < -1 || vec_z > 1)
        return(1);
    return(0);
}

int check_fov(char *fov)
{
    int converted;

    converted = ft_atoi(fov);
    if(only_digits(fov))
        return(1);
    if(converted < 0 || converted > 180)
        return(1);
    return(0);
    
}