#include "miniRT.h"

int check_extension(char *file_name)
{
    char *ext;

    if(!ft_strchr(file_name, '.'))
        return(1);
    ext = file_name + ft_strlen(file_name) - 3;
    if(ft_strncmp(ext, ".rt", ft_strlen(ext)))
        return(1);
    return(0);
}

int parse_input(int ac, char **av)
{
    char *buffer;
    int file_no;
    (void)ac;
    
    buffer = malloc(sizeof(int));
    if(check_extension(av[1]))
        return(write(STDERR_FILENO, ERR_FILE_NAME, 33));
    file_no = open(av[1], O_RDONLY);
    if(file_no == -1)
        return(write(STDERR_FILENO, ERROR_FILE, 29));
    if(!read(file_no, buffer, sizeof(int)))
        return(close(file_no), write(STDERR_FILENO, ERR_READ_FILE, 28));
    close(file_no);
    return(0);
}

int get_type(char *line)
{
    char **tab;

    tab = ft_split(line, ' ');
    if(!ft_strncmp(tab[0], "A", ft_strlen(tab[0])))
        return(AMBIENT);
    else if(!ft_strncmp(tab[0], "C", ft_strlen(tab[0])))
        return(CAMERA);
    else if(!ft_strncmp(tab[0], "L", ft_strlen(tab[0])))
        return (LIGHT);
    else if(!ft_strncmp(tab[0], "sp", ft_strlen(tab[0])))
        return(SPHERE);
    else if(!ft_strncmp(tab[0], "cy", ft_strlen(tab[0])))
        return(CYLINDRE);
    else if(!ft_strncmp(tab[0], "pl", ft_strlen(tab[0])))
        return(PLAN);
    else if(!ft_strncmp(tab[0], "tr", ft_strlen(tab[0])))
        return(TRIANGLE);
    else    
        return(-1);
}

int init_and_parse(t_data *data, char **av)
{
    int file_no;
    char *line;
    char *sp_line;
    int type;
    (void)type;

    file_no = open(av[1], O_RDONLY);
    init_scene(data);
    while(1)
    {
        line = get_next_line(file_no);
        if(!line)
            break;
        sp_line = spaces_check(line);
        if(!sp_line)
            continue;
        type = get_type(sp_line);
        if(add_to_struct(data, type, sp_line) > 6)
            return (1);
    }
    return(0);
}

int parsing(t_data *data, int ac, char **av)
{
    if(parse_input(ac, av))
        return(1);
    if(init_and_parse(data, av))
        return(1);
    //print_struct(data);
    return(0);
}
