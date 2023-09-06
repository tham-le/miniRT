#ifndef STRUCTS_H
# define STRUCTS_H

enum e_type{
    AMBIENT,
    CAMERA,
    LIGHT,
    SPHERE,
    CYLINDRE, 
    PLAN,
};

typedef struct s_color
{
    int r;
    int g;
    int b;
}              t_color;

typedef struct s_vector
{
    double x;
    double y;
    double z;
}              t_vector;

typedef struct s_ambient
{
    enum e_type type;
    int ratio;
    t_color color;
}           t_ambient;

typedef struct s_camera
{
    enum e_type   type;
    t_vector position;
    t_vector vector;
    int      fov;
}           t_camera;

typedef struct s_light
{
    enum e_type   type;
    t_vector position;
    int      ratio;
    t_color color;
    struct s_light *next;
}           t_light;

typedef struct s_objs
{
    enum e_type type;
    void        *polym;
    struct t_objs *next;
}               t_objs;

typedef struct s_scene
{
    t_ambient	ambient;
    t_light		light;
    t_camera	camera;
}       		t_scene;

typedef struct s_sphere
{
    enum e_type type;
    t_vector point;
    t_color color;
    int diameter;
    struct t_objs *next;
}           t_sphere;

typedef struct s_cylindre
{
    enum e_type type;
    t_vector center;
    t_vector norm;
    int diameter;
    int height;
    t_color color;
    struct t_objs *next;
}           t_cylindre;

typedef struct s_plan
{
    enum e_type type;
    t_vector point;
    t_vector orientation;
    t_color color;
    struct t_objs *next;
}               t_plan;


#endif