#include "miniRT.h"

void print_struct(t_data *data)
{
    t_objs *obj;
    t_scene scene;

    obj = data->objs;
    scene = data->scene;
    printf("STRUCT: \n");
    while(obj)
    {
        if(obj->type == SPHERE)
            printf("SPHERE: coord: [%f, %f, %f], diametre: [%f], color: [%d, %d, %d]\n", obj->position.x, obj->position.y, obj->position.z, obj->diametre, obj->color.r, obj->color.g, obj->color.b);
        if(obj->type == CYLINDRE)
            printf("CYLINDRE: coord: [%f, %f, %f], vector: [%f, %f, %f], diametre: [%f], height: [%f], color: [%d, %d, %d]\n", obj->position.x, obj->position.y, obj->position.z, obj->vector.x, obj->vector.y, obj->vector.z, obj->diametre, obj->height, obj->color.r, obj->color.g, obj->color.b);
        if(obj->type == PLAN)
            printf("PLAN: coord: [%f, %f, %f], vector: [%f, %f, %f], color: [%d, %d, %d]\n", obj->position.x, obj->position.y, obj->position.z, obj->vector.x, obj->vector.y, obj->vector.z, obj->color.r, obj->color.g, obj->color.b);
        obj = obj->next;
    }
    printf("AMBIENT: ratio: [%f], rgb: [%d,%d,%d]\n", scene.ambient.ratio, scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
    printf("CAMERA: coord: [%f,%f,%f], vector: [%f,%f,%f], fov: [%d]\n", scene.camera.position.x, scene.camera.position.y, scene.camera.position.z, scene.camera.vector.x, scene.camera.vector.y, scene.camera.vector.z, scene.camera.fov);
    printf("LIGHT: coord: [%f,%f,%f], ratio: [%f], color: [%d,%d,%d]\n", scene.light.position.x, scene.light.position.y, scene.light.position.z, scene.light.ratio, scene.light.color.r, scene.light.color.g, scene.light.color.b);
        
}
