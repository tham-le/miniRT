/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:35:49 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/27 17:55:37 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"
# include "utils.h"
# include "libft.h"

# define ERROR_NB_ARGS_AMB "Error: line %d: at least 2 arguments \
are required for ambient\n"
# define ERROR_NB_ARGS_LIGHT "Error: line %d: at least 4 arguments \
are required for light\n"
# define ERROR_NB_ARGS_CAM "Error: line %d: at least 4 arguments \
are required for camera\n"
# define ERROR_RATIO "Error: line %d: invalid ratio\n"
# define ERROR_FILE "Error: file cannot be opened\n"
# define ERR_READ_FILE "Error: cannot read the file\n"
# define ERR_INFOS_ELEM "Error: line %d: infos are not correct\n"
# define ERR_FILE_NAME "Error: file should be a .rt file\n"
# define ERR_NB_AMBIENT "Error: line %d: only one ambient light is allowed\n"
# define ERR_NB_CAMERA "Error: line %d: only one camera is allowed\n"
# define ERR_NB_LIGHT "Error: only one light is allowed\n"
# define ERR_NAME_ELMT "Error: invalid name of element\n"
# define ERROR_POS_ARGS "Error: line %d: all position/vector arguments \
should be written in this format: x,x,x\n"
# define ERROR_POS_ARGS_DIGIT "Error: line %d: a position/vector argument \
contains a character that is not a digit\n"
# define ERROR_COL_ARGS "Error: line %d: all color arguments should be written \
in this format: x,x,x with a x in the range from 0 to 255\n"
# define ERROR_COL_ARGS_DIGIT "Error: line %d: one of rgb color contains \
a character that is not a digit\n"
# define ERROR_COL_ARGS_RANGE "Error: line %d: one of the rgb colors \
is not within the range 0 to 255\n"
//PARSING
//Functions from file : check_extension.c
int			check_extension(char *file_name);

//Functions from file : options.c
int			get_pattern_type(char *ptrn);

void		add_pattern_type(t_objs *obj, char **elems);

void		add_options(t_objs *obj, char **elems);

//Functions from file : add_objs_elems.c
void		push_light(t_light *obj, t_light **objs);

void		push_object(t_objs *obj, t_objs **objs);

int			is_void(char c);

//Functions from file : parsing.c
int			parse_input(int ac, char **av);

int			get_type_suite(char **tab);

int			get_type(char *line);

int			init_and_parse(t_data *data, char **av);

int			parsing(t_data *data, int ac, char **av);

//Functions from file : parse_file.c
//Functions from file : infos_elements.c
char		*before_dot(char *elems, int *dot);

char		*after_dot(char *elems, int *dot);

int			nb_dots(char *elems);

int			only_digits(char *str);

int			check_float(char *elems);

//Functions from file : range_check.c
int			check_ratio(char *flt, t_data *data);

int			check_vector(char *vect, t_data *data);

int			check_fov(char *fov);

//Functions from file : add_a_cylindre.c
int			err_cyl(char **elems, t_objs **obj, t_data *data);

int			add_a_cylindre(t_data *data, char **elems);

//Functions from file : add_a_plan.c
int			add_a_plan(t_data *data, char **elems);

//Functions from file : add_scene_elems.c
int			add_ambient(t_data *data, char **elems);

int			add_light(t_data *data, char **elems);

int			add_camera(t_data *data, char **elems);

//Functions from file : parse_helpers.c
char		*dup_one(char c);

char		*str_concate(char *s, char c);

char		*spaces_check(char *line);

//Functions from file : add_a_sphere.c
int			err_sphere(char **elems, t_objs **obj, t_data *data);

int			add_a_sphere(t_data *data, char **elems);

//Functions from file : add_a_triangle.c
int			err_tri(char **elems, t_objs **obj, t_data *data);

int			add_a_triangle(t_data *data, char **elems);

//Functions from file : infos.c
int			check_position(char *elems, t_data *data);

t_vector	get_position(char *elems);

int			check_color(char *elems, t_data *data);

t_color		get_color(char *elems);

//Functions from file : file_elements.c
int			first_element(char *elem);

int			add_to_struct_suite(t_data *data, int type, char **elems);

int			add_to_struct(t_data *data, int type, char *line);

//Functions from file : init_scene.c
void		init_scene(t_data *data);

void		init_sc_camera(t_camera camera);

void		init_sc_light(t_light light);

void		init_sc_ambient(t_ambient ambient);

//Functions from file : add_a_cone.c
int			err_cone(char **elems, t_objs **obj, t_data *data);

int			add_a_cone(t_data *data, char **elems);

//Functions from file : add_options.c
void		add_bmp_file(t_objs *obj, char **elems);

void		add_reflect_opt(t_objs *obj, char **elems);

void		add_diffuse_opt(t_objs *obj, char **elems);

void		add_shine_opt(t_objs *obj, char **elems);

void		add_specular_opt(t_objs *obj, char **elems);
#endif
