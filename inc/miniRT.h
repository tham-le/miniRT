#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

# define ERROR_NUM_ARGS "Parse error: Invalid number of arguments\n"
# define ERROR_FILE "Parse error: file cannot be opened\n"
# define ERR_READ_FILE "Parse error: cannot read the file\n"

enum e_type{
    PLAN,
    CYLINDRE, 
    SPHERE,
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

int parsing(int ac, char **av);

#endif 