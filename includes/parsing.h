/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:35:49 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/16 15:53:18 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H


#include "structs.h"
#include "utils.h"
#include "libft.h"

# define ERROR_NUM_ARGS "Error: Invalid number of arguments\n"
# define ERROR_FILE "Error: file cannot be opened\n"
# define ERR_READ_FILE "Error: cannot read the file\n"
# define ERR_INFOS_ELEM "Error: infos are not correct\n"
# define ERR_FILE_NAME "Error: file should be a .rt file\n"
# define ERR_NB_AMBIENT "Error: only one ambient light is allowed\n"
# define ERR_NB_CAMERA "Error: only one camera is allowed\n"
# define ERR_NB_LIGHT "Error: only one light is allowed\n"
# define ERR_NAME_ELMT "Error: invalid name of element\n"

//PARSING
int parsing(t_data *data, int ac, char **av);
int init_and_parse(t_data *data, char **av);
int parse_input(int ac, char **av);
int check_line(t_scene *sc, t_objs *objs, char *line);
int first_element(char *elem);
int add_to_struct(t_data *data, int type, char *line);
int add_ambient(t_data *data, char **elems);
int add_light(t_data *data, char **elems);
int add_camera(t_data *data, char **elems);
int add_a_sphere(t_data *data, char **elems);
int add_a_cylindre(t_data *data, char **elems);
int add_a_plan(t_data *data, char **elems);
int add_a_triangle(t_data *data, char **elems);
t_vector get_position(char *elems);
t_color get_color(char *elems);
int check_position(char *elems);
int check_color(char *elems);
void init_scene(t_data *data);
void init_sc_camera(t_camera camera);
void init_sc_light(t_light  light);
void init_sc_ambient(t_ambient ambient);
int check_extension(char *file_name);
int check_float(char *elems);
int only_digits(char *str);
char *after_dot(char *elems, int *dot);
char *before_dot(char *elems, int *dot);
int is_void(char c);
int check_ratio(char *flt);
int check_vector(char *vect);
int check_fov(char *fov);
char *spaces_check(char *line);
char	*str_concate(char *s, char c);
char *dup_one(char c);

//DEBUG
void print_struct(t_data *data);


#endif
