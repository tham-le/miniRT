#include "../../inc/miniRT.h"

void init_scene(t_scene *sc)
{
    init_sc_ambient(sc);
    init_sc_light(sc);
    init_sc_camera(sc);
}

void init_sc_camera(t_scene *sc)
{
    sc->camera.fov = 0;
    sc->camera.position.x = 0;
    sc->camera.position.y = 0;
    sc->camera.position.z = 0;
    sc->camera.vector.x = 0;
    sc->camera.vector.y = 0;
    sc->camera.vector.z = 0;
}

void init_sc_light(t_scene *sc)
{
    sc->light.color.r = 0;
    sc->light.color.g = 0;
    sc->light.color.b = 0;
    sc->light.position.x = 0;
    sc->light.position.y = 0;
    sc->light.position.z = 0;
    sc->light.ratio = 0;
}

void init_sc_ambient(t_scene *sc)
{
    sc->ambient.color.r = 0;
    sc->ambient.color.g = 0;
    sc->ambient.color.b = 0;
    sc->ambient.ratio = 0;
    sc->camera.fov = 0;
    sc->camera.position.x = 0;
    sc->camera.position.y = 0;
    sc->camera.position.z = 0;
    sc->camera.vector.x = 0;
    sc->camera.vector.y = 0;
    sc->camera.vector.z = 0;
}