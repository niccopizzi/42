#ifndef OBJECTS_H
#define OBJECTS_H

#include "vectors.h"
#include "ray.h"
#include "../lib/minift/include/minift.h"

typedef enum e_type
{
    SP,
    PL,
    CY,
}   t_type;

typedef struct s_object
{
    t_type      type;
    float       radius;
    float       height;
    t_point4    point;
    t_vec4      normal;
    t_point4    center;
    t_vec4      axis;
    t_color     color;
}   t_object;

typedef struct s_intersect
{
    float       t;  
    t_object*   intersected;
     
}   t_intersect;

t_object        sphere_new(t_point4 center, float radius);
t_intersect*    hit(const t_da *intersections);
bool            sphere_hit_test(t_ray *ray, t_object *sphere, t_da *intersections);

#endif  //OBJECTS_H