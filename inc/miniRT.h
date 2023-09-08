#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include "structs.h"
#include "libft.h"

# define FD_SIZE 1024
# define BUFFER_SIZE 1024

# define ERROR_NUM_ARGS "Parse error: Invalid number of arguments\n"
# define ERROR_FILE "Parse error: file cannot be opened\n"
# define ERR_READ_FILE "Parse error: cannot read the file\n"
# define ERR_INFOS_ELEM "Error: infos are not correct\n"

//PARSING
int parsing(t_scene *sc, t_objs *obj, int ac, char **av);
int init_and_parse(t_scene *sc, t_objs *objs, char **av);
int parse_input(int ac, char **av);
int check_line(t_scene *sc, t_objs *objs, char *line);
int first_element(char *elem);
int add_to_struct(t_scene *sc, t_objs *obj, int type, char *line);
int add_ambient(t_scene *sc, char **elems);
int add_light(t_scene *sc, char **elems);
int add_camera(t_scene *sc, char **elems);
int add_a_sphere(t_objs **obj, char **elems);
int add_a_cylindre(t_objs *obj, char **elems);
int add_a_plan(t_objs *obj, char **elems);
t_vector get_position(char *elems);
t_color get_color(char *elems);
int check_position(char *elems);
int check_color(char *elems);
void init_scene(t_scene *sc);
void init_sc_camera(t_scene *sc);
void init_sc_light(t_scene *sc);
void init_sc_ambient(t_scene *sc);

//DEBUG
void print_struct(t_scene *sc, t_objs *obj);

//GNL
char	*get_next_line(int fd);

#endif 