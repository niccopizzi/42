#ifndef RAY_H
#define RAY_H

#include "vectors.h"
#include <limits.h>

#define T_MAX 1000
#define T_MIN 0.1

typedef enum    e_rtype
{
    PRIMARY,
    SHADOW,
    REFLECTIVE,
    REFRACTIVE,
}   t_rtype;

typedef struct s_ray
{
    t_rtype         type;
    float           min_t;
    t_vec4          direction;
    t_point4        origin;
} t_ray;

t_ray       ray_create(t_point4 origin, t_vec4 direction, t_rtype type);
t_point4    ray_at(t_ray ray, float time);
#endif // RAY_H