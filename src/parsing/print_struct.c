#include "../../inc/miniRT.h"

void print_struct(t_scene *sc, t_objs *obj)
{
    int i;

    i = 0;
    while(obj->next != NULL)
    {
        printf("%d: obj->type = %d, obj->polym: %p\n", i, obj->type, obj->polym);
        i++;
    }
    printf("camera: fov:%d, x:%f, y:%f z:%f\n", sc->camera.fov, sc->camera.position.x, sc->camera.position.y, sc->camera.position.z);
}