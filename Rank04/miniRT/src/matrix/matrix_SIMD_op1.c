#include "matrix.h"
#include <stdio.h>

void    matrix4_setup_identity(t_mat4 m)
{
    (m)[0] = vector_from_array((float[]){1, 0, 0, 0});
    (m)[1] = vector_from_array((float[]){0, 1, 0, 0});
    (m)[2] = vector_from_array((float[]){0, 0, 1, 0});
    (m)[3] = vector_from_array((float[]){0, 0, 0, 1});
}

inline bool    matrix4_compare_eq(t_mat4 m1, t_mat4 m2)
{
    return (vector_compare_eq(m1[0], m2[0]) && 
            vector_compare_eq(m1[1], m2[1]) &&
            vector_compare_eq(m1[2], m2[2]) &&
            vector_compare_eq(m1[3], m2[3]));
}

inline void    matrix4_transpose(t_mat4 m)
{
    _MM_TRANSPOSE4_PS(m[0], m[1], m[2], m[3]);
}

inline void    matrix4_copy(t_mat4 dest, t_mat4 src)
{
    dest[0] = _mm_moveldup_ps(src[0]);
    dest[1] = _mm_moveldup_ps(src[1]);
    dest[2] = _mm_moveldup_ps(src[2]);
    dest[3] = _mm_moveldup_ps(src[3]);
}

void    matrix4_mult_mat4(t_mat4 res, t_mat4 m1, t_mat4 m3)
{
    t_mat4  m2;

    matrix4_copy(m2, m3);
    matrix4_transpose(m2);
    (res)[0] = _mm_load_ps((float[]){ vector_dot_product(m1[0], m2[0]),
                                vector_dot_product(m1[0], m2[1]), 
                                vector_dot_product(m1[0], m2[2]),
                                vector_dot_product(m1[0], m2[3])});
    (res)[1] = _mm_load_ps((float[]){ vector_dot_product(m1[1], m2[0]),
                                vector_dot_product(m1[1], m2[1]), 
                                vector_dot_product(m1[1], m2[2]),
                                vector_dot_product(m1[1], m2[3])});
    (res)[2] = _mm_load_ps((float[]){ vector_dot_product(m1[2], m2[0]),
                                vector_dot_product(m1[2], m2[1]), 
                                vector_dot_product(m1[2], m2[2]),
                                vector_dot_product(m1[2], m2[3])});
    (res)[3] = _mm_load_ps((float[]){ vector_dot_product(m1[3], m2[0]),
                                vector_dot_product(m1[3], m2[1]), 
                                vector_dot_product(m1[3], m2[2]),
                                vector_dot_product(m1[3], m2[3])});
}