#include "objects.h"

inline t_object    sphere_new(t_point4 center, float radius)
{
    t_object    sphere;

    sphere.center = center;
    sphere.type = SP;
    sphere.radius = radius;
    sphere.transform = matrix4_identity();
    sphere.color = vector_from_array((float[]){1,0,0,0});
    return (sphere);
}

inline void     sphere_set_transform(t_object *sphere, t_mat4 tm)
{
    sphere->transform = tm;
}

bool  sphere_hit_test(t_ray *ray, t_object *sphere, t_da *intersections)
{
    t_vec4  sp_to_ray_vec;
    t_ray   ray_t;
    float   a;
    float   b;
    float   c;
    float   d;

    ray_t = ray_transform(ray, matrix4_invert(sphere->transform));
    sp_to_ray_vec = ray_t.origin - sphere->center;
    a = vector_dot_product(ray_t.direction, ray_t.direction);
    b = 2 * vector_dot_product(ray_t.direction, sp_to_ray_vec);
    c = vector_dot_product(sp_to_ray_vec, sp_to_ray_vec) - 1;
    d = b * b - (4 * (a * c));

    if (d < 0)
        return (false);
    return (da_append(intersections, (void *) &(t_intersect){
        .t = (-b - sqrt(d)) / (2 * a), .intersected = sphere}) 
        && da_append(intersections, (void *) &(t_intersect){
        .t = (-b + sqrt(d)) / (2 * a), .intersected = sphere}));
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