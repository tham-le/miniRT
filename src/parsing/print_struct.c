#include "../../inc/miniRT.h"

void print_struct(t_scene *sc, t_objs *obj)
{
    int i;

    i = 0;
    while(obj)
    {
        printf("%d: obj->type = %d, obj->polym: %p\n", i, obj->type, obj->polym);
        obj = obj->next;
        i++;
    }
    printf("camera: fov:%d, position: x:%f, y:%f z:%f, vector: x:%f,y:%f,z:%f\n", sc->camera.fov, sc->camera.position.x, sc->camera.position.y, sc->camera.position.z, sc->camera.vector.x, sc->camera.vector.y, sc->camera.vector.z);
    printf("light: position: x:%f,y:%f,z:%f, ratio: %d, color: r:%d,g:%d,b:%d\n", sc->light.position.x, sc->light.position.y, sc->light.position.z, sc->light.ratio, sc->light.color.r, sc->light.color.g, sc->light.color.b);
    printf("ambient: ratio: %d, color: r:%d,g:%d,b:%d\n", sc->ambient.ratio, sc->ambient.color.r, sc->ambient.color.g, sc->ambient.color.b);

}