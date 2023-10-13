#include "miniRT.h"
#include <stdio.h>

void print_struct(t_data *data)
{
    t_objs *obj;
    t_light *lit;
    t_scene scene;

    obj = data->objs;
    scene = data->scene;
    lit = data->scene.light;
    printf("STRUCT: \n");
    while(obj)
    {
        if(obj->type == SPHERE)
            printf("SPHERE: coord: [%f, %f, %f], radius: [%f], color: [%f, %f, %f]\n", obj->position.x, obj->position.y, obj->position.z, obj->radius, obj->color.r, obj->color.g, obj->color.b);
        if(obj->type == CYLINDER)
            printf("CYLINDRE: coord: [%f, %f, %f], vector: [%f, %f, %f], radius: [%f], height: [%f], color: [%f, %f, %f]\n", obj->position.x, obj->position.y, obj->position.z, obj->vector.x, obj->vector.y, obj->vector.z, obj->radius, obj->height, obj->color.r, obj->color.g, obj->color.b);
        if(obj->type == PLAN)
            printf("PLAN: coord: [%f, %f, %f], vector: [%f, %f, %f], color: [%f, %f, %f]\n", obj->position.x, obj->position.y, obj->position.z, obj->vector.x, obj->vector.y, obj->vector.z, obj->color.r, obj->color.g, obj->color.b);
        if (obj->type == CONE)
            printf("CONE: coord: [%f, %f, %f], vector: [%f, %f, %f], radius: [%f], height: [%f], color: [%f, %f, %f]\n", obj->position.x, obj->position.y, obj->position.z, obj->vector.x, obj->vector.y, obj->vector.z, obj->radius, obj->height, obj->color.r, obj->color.g, obj->color.b);
        if(obj->type == TRIANGLE)
            printf("TRIANGLE: coord: [%f, %f, %f], vector: [%f, %f, %f], color: [%f, %f, %f]\n", obj->position.x, obj->position.y, obj->position.z, obj->vector.x, obj->vector.y, obj->vector.z, obj->color.r, obj->color.g, obj->color.b);
        obj = obj->next;
    }
    printf("AMBIENT: ratio: [%f], rgb: [%f,%f,%f]\n", scene.ambient.ratio, scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
    printf("CAMERA: coord: [%f,%f,%f], vector: [%f,%f,%f], fov: [%f]\n", scene.camera.position.x, scene.camera.position.y, scene.camera.position.z, scene.camera.vector.x, scene.camera.vector.y, scene.camera.vector.z, scene.camera.fov);
    while(lit)
    {
        printf("LIGHT: coord: [%f,%f,%f], ratio: [%f], color: [%f,%f,%f]\n", lit->position.x, lit->position.y, lit->position.z, lit->ratio, lit->color.r, lit->color.g, lit->color.b);
        lit = lit->next;
    }

}
