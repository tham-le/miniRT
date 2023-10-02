#include "miniRT.h"


void init_scene(t_data *data)
{
    init_sc_ambient(data->scene.ambient);
    init_sc_light(data->scene.light);
    init_sc_camera(data->scene.camera);
}

void init_sc_camera(t_camera camera)
{
    (void)camera;
    camera.fov = 0;
    camera.position.x = 0;
    camera.position.y = 0;
    camera.position.z = 0;
    camera.vector.x = 0;
    camera.vector.y = 0;
    camera.vector.z = 0;
}

void init_sc_light(t_light light)
{
    (void)light;
    light.color.r = 0;
    light.color.g = 0;
    light.color.b = 0;
    light.position.x = 0;
    light.position.y = 0;
    light.position.z = 0;
    light.ratio = 0;
}

void init_sc_ambient(t_ambient ambient)
{
    (void)ambient;
    ambient.color.r = 0;
    ambient.color.g = 0;
    ambient.color.b = 0;
    ambient.ratio = 0;
}