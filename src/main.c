#include "../inc/miniRT.h"

int main(int ac, char **av)
{
    t_scene sc;
    t_objs obj;

    if(parsing(&sc, &obj, ac, av))
        return(1);
    return (0);
}