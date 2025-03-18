#include "ray.h"


inline t_ray   ray_create(t_point4 origin, t_vec4 direction, t_rtype type)
{
    t_ray   ray;

    ray.type = type;
    ray.origin = origin;
    ray.direction = direction;

    return (ray);
}

inline  t_point4    ray_at(t_ray ray, float time)
{
    return (vector_at(ray.origin, ray.direction, time));
}