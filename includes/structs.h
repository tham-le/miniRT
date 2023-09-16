/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:54:20 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/16 16:15:59 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_type{
    AMBIENT,
    CAMERA,
    LIGHT,
    SPHERE,
    CYLINDRE,
    PLAN,
}          t_type;

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

typedef struct s_color
{
    int r;
    int g;
    int b;
}              t_color;

typedef struct s_vector
{
    float x;
    float y;
    float z;
}              t_vector;

typedef struct s_ambient
{
    float ratio;
    t_color color;
}           t_ambient;

typedef struct s_camera
{
	t_vector	position;
	t_vector	vector;
	int			fov;
}		t_camera;

typedef struct s_light
{
    t_vector position;
    float      ratio;
    t_color color;
}           t_light;

typedef struct s_objs
{
    t_type type;
    int fov;
    float diametre;
    float height;
    float ratio;
    t_color color;
    t_vector position;
    t_vector vector;
    struct s_objs *next;
}               t_objs;

typedef struct s_scene
{
    t_ambient	ambient;
    t_light		light;
    t_camera	camera;
    int nb_amb;
    int nb_light;
    int nb_cam;
}       		t_scene;

typedef struct	s_settings
{
	int			width;
	int			height;
	int			render_scale;
}				t_settings;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_scene		scene;
	t_objs		*objs;
	t_settings	settings;
}				t_data;


#endif
