#include "miniRT.h"

void add_bmp_file(t_objs *obj, char **elems)
{
    int i;

    i = 3;
    while(i < ft_tabsize(elems))
    {
        if(open(elems[i], O_RDONLY) != -1)
        {
            obj->bump_img = elems[i];
            // printf("file is: %s\n", obj->bump_img);
            return;
        }
        i++;
    }
}

void add_reflect_opt(t_objs *obj, char **elems)
{
    int i;

    i = 3;
    while(i < ft_tabsize(elems))
    {
        if(!ft_strncmp("-refl:", elems[i], 6))
        {
            if(check_float(elems[i] + 6))
                return;
            obj->reflective= ft_atod(elems[i] + 6);
            // printf("reflectiveness: %f\n", obj->reflective);
            return;
        }
        i++;
    }
}

void add_diffuse_opt(t_objs *obj, char **elems)
{
    int i;

    i = 3;
    while(i < ft_tabsize(elems))
    {
        if(!ft_strncmp("-diff:", elems[i], 6))
        {
            if(check_float(elems[i] + 6))
                return;
            obj->diffuse= ft_atod(elems[i] + 6);
            // printf("diffuse: %f\n", obj->diffuse);
            return;
        }
        i++;
    }
}

void add_shine_opt(t_objs *obj, char **elems)
{
    int i;

    i = 3;
    while(i < ft_tabsize(elems))
    {
        if(!ft_strncmp("-shine:", elems[i], 7))
        {
            if(check_float(elems[i] + 7))
                return;
            obj->shininess= ft_atod(elems[i] + 7);
            // printf("shininess: %f\n", obj->shininess);
            return;
        }
        i++;
    }
}

void add_specular_opt(t_objs *obj, char **elems)
{
    int i;

    i = 3;
    while(i < ft_tabsize(elems))
    {
        if(!ft_strncmp("-spec:", elems[i], 6))
        {
            if(check_float(elems[i] + 6))
                return;
            obj->specular= ft_atod(elems[i] + 6);
            // printf("specular: %f\n", obj->specular);
            return;
        }
        i++;
    }
}

void add_options(t_objs *obj, char **elems)
{
    add_bmp_file(obj, elems);
    add_reflect_opt(obj, elems);
    add_diffuse_opt(obj, elems);
    add_shine_opt(obj, elems);
    add_specular_opt(obj, elems);

}