#include "objects.h"

inline t_object    sphere_new(t_point4 center, float diameter)
{
    t_object    sphere;

    sphere.center = center;
    sphere.type = SP;
    sphere.diameter = diameter;

    return (sphere);
}

void  sphere_hit_test(t_ray *ray, t_object *sphere, t_intersect *in)
{
    t_vec4  str = ray->origin - sphere->center;
    float   a = vector_dot_product(ray->direction, ray->direction);
    float   b = 2 * vector_dot_product(ray->direction, str);
    float   c = vector_dot_product(str, str) - 1;
    float   sqrtd;

    float   d = b * b - (4 * (a * c));

    if (d < 0)
    {
        in->count = 0;
        return;
    }
    sqrtd = sqrt(d);
    in->count = 2;
    in->t[0] = (-b - sqrtd) / (2 * a);
    in->t[1] = (-b + sqrtd) / (2 * a);
    in->intersected = sphere;
}

/* float hit_sphere_geom(t_ray *ray, t_object *sphere)
{
    t_vec4  oc;
    bool    inside;
    float   lensq;
    float   tca;
    float   t2hc;
    float   r2;

    r2 = obj->diameter * 0.5 * obj->diameter * 0.5;
    oc = ray->direction - obj->center;
    lensq = vector_len_squared(oc);
    inside = lensq < r2;
    tca = vector_dot_product(oc, ray->direction);
    if (tca < 0 && !inside)
        return (0);
    t2hc = r2 - (lensq - (tca * tca));
    if (t2hc < 0)
        return (0);
    if (inside)
        return (tca + sqrt(t2hc));
    return (tca - sqrt(t2hc));
} */