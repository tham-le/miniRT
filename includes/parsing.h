/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:35:49 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/29 17:06:39 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H


#include "structs.h"
#include "utils.h"
#include "libft.h"

# define ERROR_NB_ARGS_AMB "Error: line %d: at least 2 arguments are required for ambient\n"
# define ERROR_NB_ARGS_LIGHT "Error: line %d: at least 4 arguments are required for light\n"
# define ERROR_NB_ARGS_CAM "Error: line %d: at least 4 arguments are required for camera\n"
# define ERROR_RATIO "Error: line %d: invalid ratio\n"
# define ERROR_FILE "Error: file cannot be opened\n"
# define ERR_READ_FILE "Error: cannot read the file\n"
# define ERR_INFOS_ELEM "Error: line %d: infos are not correct\n"
# define ERR_FILE_NAME "Error: file should be a .rt file\n"
# define ERR_NB_AMBIENT "Error: line %d: only one ambient light is allowed\n"
# define ERR_NB_CAMERA "Error: line %d: only one camera is allowed\n"
# define ERR_NB_LIGHT "Error: only one light is allowed\n"
# define ERR_NAME_ELMT "Error: invalid name of element\n"
# define ERROR_POS_ARGS "Error: line %d: all position/vector arguments should be written in this format: x,x,x\n"
# define ERROR_POS_ARGS_DIGIT "Error: line %d: a position/vector argument contains a character that is not a digit\n"
# define ERROR_COL_ARGS "Error: line %d: all color arguments should be written in this format: x,x,x with a x in the range from 0 to 255\n"
# define ERROR_COL_ARGS_DIGIT "Error: line %d: one of rgb color contains a character that is not a digit\n"
# define ERROR_COL_ARGS_RANGE "Error: line %d: one of the rgb colors is not within the range 0 to 255\n"
//PARSING
int			parsing(t_data *data, int		 ac, char **av);
int			init_and_parse(t_data *data, char **av);
int			parse_input(int		 ac, char **av);
int			check_line(t_scene *sc, t_objs *objs, char *line);
int			first_element(char *elem);
int			add_to_struct(t_data *data, int		 type, char *line);
int			add_ambient(t_data *data, char **elems);
int			add_light(t_data *data, char **elems);
int			add_camera(t_data *data, char **elems);
int			add_a_sphere(t_data *data, char **elems);
int			add_a_cylindre(t_data *data, char **elems);
int			add_a_plan(t_data *data, char **elems);
int			add_a_triangle(t_data *data, char **elems);
int add_a_cone(t_data *data, char **elems);
t_vector	get_position(char *elems);
t_color		get_color(char *elems);
int			check_position(char *elems, t_data *data);
int			check_color(char *elems, t_data *data);
void		init_scene(t_data *data);
void		init_sc_camera(t_camera camera);
void		init_sc_light(t_light  light);
void		init_sc_ambient(t_ambient ambient);
int			check_extension(char *file_name);
int			check_float(char *elems);
int			only_digits(char *str);
char		*after_dot(char *elems, int		 *dot);
char		*before_dot(char *elems, int		 *dot);
int			is_void(char c);
int	check_ratio(char *flt, t_data *data);
int			check_vector(char *vect, t_data *data);
int			check_fov(char *fov);
char		*spaces_check(char *line);
char		*str_concate(char *s, char c);
char		*dup_one(char c);
t_xpm_img	*load_img(char *bmp_img, void *mlx_ptr);
void	push_light(t_light *obj, t_light **objs);
void    readbump_img(t_objs *obj);
void add_options(t_objs *obj, char **elems);
void add_reflect_opt(t_objs *obj, char **elems);
void add_diffuse_opt(t_objs *obj, char **elems);
void add_shine_opt(t_objs *obj, char **elems);
void add_specular_opt(t_objs *obj, char **elems);
void	add_bmp_file(t_objs *obj, char **elems);
int	add_to_struct_suite(t_data *data, int type, char **elems);
int	convert_to_color(char pixel, t_colors_bmp **pixel_lst);
void	push_bump_color(t_colors_bmp *obj, t_colors_bmp **objs);
//DEBUG
void		print_struct(t_data *data);
void free_all(t_data *data);

#endif
