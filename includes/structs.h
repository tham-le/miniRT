/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:03:31 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/18 21:05:44 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef double				t_mat4[4][4];
typedef double				t_mat3[3][3];
typedef double				t_mat2[2][2];

typedef enum e_type{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLAN,
	CYLINDER,
	CONE,
	TRIANGLE,
	DIMENSIONS,
	COMMENT,
}		  t_type;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	struct s_color	*next;
}			  t_color;

typedef struct s_vector
{
	float x;
	float y;
	float z;
	float w;
}			t_vector;

typedef struct s_ambient
{
	float ratio;
	t_color color;
}		t_ambient;

typedef struct s_camera
{
	t_vector	position;
	t_vector	vector;
	double			fov;
	double 		aspect;
	double		pixel_size;
	double		half_width;
	double		half_height;
	double		phi;
	double		theta;
	t_mat4		transform;
	t_mat4		inverse;
}		t_camera;

typedef struct s_light
{
	t_type		type;
	t_vector	position;
	double		ratio;
	t_vector	dir;
	t_color		color;
	t_mat4		rotat;
	t_vector	rot_trans;
	t_mat4		added_rots;;
	double		theta;
	struct s_light	*next;
}		   t_light;

typedef struct s_xpm_img{

	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
	int			height;
	int			width;
}				t_xpm_img;

typedef enum s_pattern
{
	PLAIN,
	CHECKER,
	STRIPE,
	RING,
	GRADIENT,
	NOISE,
	MARBLE,
}		  t_pattern;

typedef struct s_bumpmap
{
	char 			**bump_tab;
	int				width;
	int				height;
	int 			nb_colors;
	int				char_per_pixel;
}			t_bumpmap;

typedef struct s_colors_bmp
{
	char			c;
	char	*color;
	struct s_colors_bmp	*next;
}			t_colors_bmp;

typedef struct s_objs
{
	t_type			type;
	int				fov;
	float			diametre;
	float			radius;
	float			squared_radius;
	float			height;
	float			ratio;
	double			distance_to_origin;
	void			*mlx_bmp;
	char			*img_bmp;
	void			*addr_bmp;
	void			*win_bmp;
	t_color			*bmp_col;
	int				bmp_height;
	int				bmp_width;
	int				bpp;
	int				line_length;
	int				endian;
	t_vector		vertex[3];
	t_vector		edge[3];
	t_vector		normal;
	t_color			color;
	t_vector		position;
	t_vector		vector;
	t_vector		scale;
	char			*bump_img;
	t_color 		**tab_bmp;
	t_bumpmap		*bmp_img;
	t_colors_bmp	*colors_bmp;
	t_xpm_img		*surface;
	t_xpm_img		*map;
	t_mat4			transf;
	t_mat4			inv_transf;
	t_mat4			norm_transf;
	t_mat4			added_rots;
	t_pattern		pattern_type;
	double			diffuse;
	bool			highlighted;
	double			shininess;
	double			reflective;
	double			refraction;
	double 			reflection;
	double			specular;
	struct s_objs	*next;
}			   t_objs;

typedef struct s_scene
{
	t_ambient	ambient;
	t_light		*light;
	t_camera	camera;
	int nb_amb;
	int nb_light;
	int nb_cam;
}	   		t_scene;

/*
hzie : horizontal size (in pixels) .
vsize : vertical size (in pixels).
half_width Stores the camera's half hsize value.
half_height Stores the camera's half vsize value.
pixel_size Stores the camera's pixel size
calculated from half_width and hsize values*/
typedef struct	s_settings
{
	float			hsize;
	float			vsize;
	float			aspect_ratio;
	float			half_width;
	float			half_height;
	float			pixel_size;
	float			cam_theta;
	float			cam_phi;
}				t_settings;

typedef struct	s_phong
{
	t_color	effective_color;
	t_color	diffuse;
	t_color	specular;
	t_color	ambient;
}			t_phong;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*img_bmp;
	char		*addr;
	int			height;
	int			width;
	int			bpp;
	int			line_length;
	int			endian;
	int			nb_lines;
	t_scene		scene;
	t_objs		*objs;
	double		reflection_depth;
}				t_data;


#endif
