#ifndef WORLD_H
#define WORLD_H

#include "camera.h"
#include "da.h"

typedef struct s_ambient_light
{
    float       ratio;
    t_color     color;
}   t_ambient_light;

typedef struct s_light
{
    float           brightness;
    t_color         color;
    t_point4        pos;
}   t_light;


typedef struct s_world
{
    t_ambient_light a_light;
    t_light         light_src;
    t_cam           cam;
    t_objects_da    objects;
} t_world;

#endif
