#include "vectors.h"

t_vec3*      vector_mult_vec(t_vec3 *res, t_vec3 *vector1, t_vec3 *vector2)
{
    res->x = vector1->x * vector2->x;
    res->y = vector1->y * vector2->y;
    res->z = vector1->z * vector2->z;

    return (res);
}

t_vec3*  vector_cross_prod(t_vec3 *res, t_vec3 *vector1, t_vec3 *vector2)
{
    res->x = (vector1->y * vector2->z) - (vector1->z * vector2->y);
    res->y = (vector1->z * vector2->x) - (vector1->x * vector2->z);
    res->z = (vector1->x * vector2->y) - (vector1->y * vector2->x);

    return (res);
}

t_vec3*  vector_translate(t_vec3 *res, t_vec3 *vector, t_vec3 *translation)
{
    res->x = vector->x + translation->x;
    res->y = vector->y + translation->y;
    res->z = vector->z + translation->z;

    return (res);
}

t_point3* vector_at(t_point3 *at, t_point3 *origin, t_vec3 *direction, float a)
{
    at->x = origin->x + direction->x * a;
    at->y = origin->y + direction->y * a;    
    at->z = origin->z + direction->z * a;

    return (at);
}