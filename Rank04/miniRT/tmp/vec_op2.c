#include "vectors.h"

t_vec3*  vector_add_vec(t_vec3 *res, t_vec3 *vector1, t_vec3 *vector2)
{
    res->x = vector1->x + vector2->x;
    res->y = vector1->y + vector2->y;
    res->z = vector1->z + vector2->z;

    return (res);
}

t_vec3*  vector_add_scalar(t_vec3 *res, t_vec3 *vector, float scalar)
{
    res->x = vector->x + scalar;
    res->y = vector->y + scalar;
    res->z = vector->z + scalar;

    return (res);
}

t_vec3*  vector_sub_vec(t_vec3 *res, t_vec3 *vector1, t_vec3 *vector2)
{
    res->x = vector1->x - vector2->x;
    res->y = vector1->y - vector2->y;
    res->z = vector1->z - vector2->z;

    return (res);
}

t_vec3*    vector_mult_scalar(t_vec3 *res, t_vec3 *vector, float scalar)
{
    res->x = vector->x * scalar;
    res->y = vector->y * scalar;
    res->z = vector->z * scalar;

    return (res);
}

t_vec3*    vector_div_scalar(t_vec3 *res, t_vec3 *vector, float scalar)
{
    float   inv_scalar;

    inv_scalar = 1 / scalar;
    res->x = vector->x * inv_scalar;
    res->y = vector->y * inv_scalar;
    res->z = vector->z * inv_scalar;

    return (res);
}