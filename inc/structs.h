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
    t_vector position;
    t_vector vector;
    int      fov;
}           t_camera;

typedef struct s_light
{
    t_vector position;
    float      ratio;
    t_color color;
}           t_light;

typedef struct s_objs
{
    t_type type;
    void        *polym;
    struct s_objs *next;
}               t_objs;

typedef struct s_scene
{
    t_ambient	ambient;
    t_light		light;
    t_camera	camera;
}       		t_scene;

typedef struct s_sphere
{
    t_vector point;
    t_color color;
    int diameter;
    struct t_objs *next;
}           t_sphere;

typedef struct s_cylindre
{
    t_vector center;
    t_vector norm;
    int diameter;
    int height;
    t_color color;
    struct t_objs *next;
}           t_cylindre;

typedef struct s_plan
{
    t_vector point;
    t_vector orientation;
    t_color color;
    struct t_objs *next;
}               t_plan;


#endif