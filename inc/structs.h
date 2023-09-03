#ifndef STRUCTS_H
# define STRUCTS_H

enum e_type{
    PLAN,
    CYLINDRE, 
    SPHERE,
    LIGHT,
    CAMERA,
};

typedef struct s_vector
{
    double x;
    double y;
    double z;
}              t_vector;

typedef struct s_ambient
{
    int ratio;
    t_vector color;
}           t_ambient;

typedef struct s_camera
{
    t_vector position;
    t_vector vector;
    int fov;
    t_vector color;
}           t_camera;

typedef struct s_light
{
    t_vector position;
    int ratio;
    t_vector color;
    struct s_light *next;
}           t_light;

typedef struct s_objs
{
    int type;
    t_vector point;
    t_vector center;
    t_vector color;
    t_vector norm;
    t_vector oriented;
    int height;
    int diameter;
    struct s_objs *next;
}       t_objs;

typedef struct s_scene
{
    int type;
    t_light *light;
    t_camera camera;

}       t_scene;




#endif