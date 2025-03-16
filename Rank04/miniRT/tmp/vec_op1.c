#include "vectors.h"

t_vec3*    vector_negate(t_vec3 *res, t_vec3 *vector)
{
    res->x = - vector->x;
    res->y = - vector->y;
    res->z = - vector->z;
    return (res);
}

t_vec3*   vector_normalize(t_vec3 *res, t_vec3 *vector)
{
    float   inv_len;
    
    if (vector->x == 0.f && vector->y == 0.f && vector->z == 0.f)
    {
        res->x = 0;
        res->y = 0;
        res->z = 0;
        return (res); 
    }
    inv_len = 1 / vector_len(vector);
    res->x = vector->x * inv_len;
    res->y = vector->y * inv_len;
    res->z = vector->z * inv_len;
    return (res);
}

float   vector_len_sqrd(t_vec3 *vector)
{
    return (vector->x * vector->x
             + vector->y * vector->y
             + vector->z * vector->z);
}

float   vector_len(t_vec3 *vector)
{
    float   len_squared;

    len_squared = vector->x * vector->x
                     + vector->y * vector->y 
                     + vector->z * vector->z;
    return (sqrt(len_squared));
}

float   vector_dot_prod(t_vec3 *vector1, t_vec3 *vector2)
{
    return (vector1->x * vector2->x +
            vector1->y * vector2->y +
            vector1->z * vector2->z);
}