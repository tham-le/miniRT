#ifndef MINIRT_H
# define MINIRT_H


enum e_type{
    PLAN, //s'il y a seulement un plan
    CYLINDRE, //s'il y a seulement un cylindre
    SPHERE, //s'il y a seulement une sphere
    plans, //s'il y a plusieurs plans
    cylindres, //s'il y a plusieurs cylindres
    spheres, //s'il y a plusieurs spheres
};

typedef struct s_plan
{
    int position[3];
    int vector[3];
    int color[3];
}           t_plan;

typedef struct s_cylindre
{
    int position[3];
    int vector[3];
    int diameter;
    int height;
    int color[3];
}           t_cylindre;

typedef struct s_sphere
{
    int position[3];
    int diameter;
    int color[3];
}           t_sphere;

typedef struct s_ambient
{
    int ratio;
    int color[3];
}           t_ambient;

typedef struct s_camera
{
    int position[3];
    int vector[3];
    int fov;
    int color[3];
}           t_camera;

typedef struct s_light
{
    int position[3];
    int ratio;
    int color[3];
}           t_light;

#endif 