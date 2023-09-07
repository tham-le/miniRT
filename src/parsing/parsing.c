#include "../../inc/miniRT.h"

int parse_input(int ac, char **av)
{
    char *buffer;
    int file_no;
    
    buffer = NULL;
    if(ac != 2)
        return(write(STDERR_FILENO, ERROR_NUM_ARGS, 42));
    file_no = open(av[1], O_RDONLY);
    if(file_no == -1)
        return(write(STDERR_FILENO, ERROR_FILE, 35));
    if(!read(file_no, buffer, sizeof(int)))
        return(close(file_no), write(STDERR_FILENO, ERR_READ_FILE, 35));
    close(file_no);
    return(0);
}

// int check_line(t_scene *sc, t_objs *objs, char *line)
// {
//     (void)sc;
//     (void)objs;
//     char **elems;
//     int type;
//     int i;

//     i = 1;
//     elems = ft_split(line, ' ');
//     if(!elems) //empty line
//         return(0);
//     type = first_element(elems[0]);
//     if(type == -1) //the type is not correct
//         return(1);
//     return(add_to_list(sc, objs, type, elems));
// }

int get_type(char *line)
{
    char **tab;

    tab = ft_split(line, ' ');
    if(!ft_strncmp(tab[0], "A", ft_strlen(tab[0])))
        return(0);
    else if(!ft_strncmp(tab[0], "C", ft_strlen(tab[0])))
        return(1);
    else if(!ft_strncmp(tab[0], "L", ft_strlen(tab[0])))
        return (2);
    else if(!ft_strncmp(tab[0], "sp", ft_strlen(tab[0])))
        return(3);
    else if(!ft_strncmp(tab[0], "cy", ft_strlen(tab[0])))
        return(4);
    else if(!ft_strncmp(tab[0], "pl", ft_strlen(tab[0])))
        return(5);
    else    
        return(6);
}

int init_and_parse(t_scene *sc, t_objs *objs, char **av)
{
    int file_no;
    char *line;
    int type;

    file_no = open(av[1], O_RDONLY);
    init_scene(sc);
    while(1)
    {
        line = get_next_line(file_no);
        if(!line)
            break;
        type = get_type(line);
        if(add_to_struct(sc, objs, type, line))
            return (1);
    }
    return(0);
}

int parsing(t_scene *sc, t_objs *objs, int ac, char **av)
{
    ft_bzero(sc, sizeof(t_scene));
    ft_bzero(objs, sizeof(t_objs));
    if(parse_input(ac, av))
        return(1);
    if(init_and_parse(sc, objs, av))
        return(1);
    print_struct(sc, objs);
    return(0);
}