/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:35:49 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/10 19:21:30 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H


#include "structs.h"
#include "utils.h"
#include "libft.h"

# define ERROR_NUM_ARGS "Parse error: Invalid number of arguments\n"
# define ERROR_FILE "Parse error: file cannot be opened\n"
# define ERR_READ_FILE "Parse error: cannot read the file\n"
# define ERR_INFOS_ELEM "Error: infos are not correct\n"
# define ERR_FILE_NAME "Error: file should be a .rt file\n"



typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_scene	scene;
	t_objs *objs;
}				t_data;

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
t_vector get_position(char *elems);
t_color get_color(char *elems);
int check_position(char *elems);
int check_color(char *elems);
void init_scene(t_scene *sc);
void init_sc_camera(t_scene *sc);
void init_sc_light(t_scene *sc);
void init_sc_ambient(t_scene *sc);
int check_extension(char *file_name);

//DEBUG
void print_struct(t_data *data);


#endif 
