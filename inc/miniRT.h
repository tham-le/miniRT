#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "structs.h"
#include "libft.h"

# define FD_SIZE 1024
# define BUFFER_SIZE 1024

# define ERROR_NUM_ARGS "Parse error: Invalid number of arguments\n"
# define ERROR_FILE "Parse error: file cannot be opened\n"
# define ERR_READ_FILE "Parse error: cannot read the file\n"

//PARSING
int parsing(t_scene *sc, t_objs *obj, int ac, char **av);
int init_and_parse(t_scene *sc, t_objs *objs, char **av);
int parse_input(int ac, char **av);
int check_line(t_scene *sc, t_objs *objs, char *line);
int first_element(char *elem);
int add_to_list(t_scene *sc, t_objs *obj, int type, char **elems);

//GNL
char	*get_next_line(int fd);

#endif 