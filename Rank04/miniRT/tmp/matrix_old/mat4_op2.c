#include "matrix.h"

t_mat4*     matrix4_mult_scalar(t_mat4 *res, t_mat4 *m1, float scalar)
{
    int         row;
    int         col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            (*res)[row][col] = (*m1)[row][col] * scalar;
            col++;
        }
        row++;
    }
    return (res);
}

t_mat4*    matrix4_mult_mat4(t_mat4 *res, t_mat4 *m1, t_mat4 *m2)
{
    int     row;
    int     col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            (*res)[row][col] = (*m1)[row][0] * (*m2)[0][col] +  
                                (*m1)[row][1] * (*m2)[1][col] +
                                (*m1)[row][2] * (*m2)[2][col] +
                                (*m1)[row][3] * (*m2)[3][col] ;
            col++;
        }
        row++;
    }
    return (res);
}

t_point3*    matrix4_mult_point(t_point3 *res, t_mat4 *m, t_point3 *point)
{

    res->x = (point->x) * ((*m)[0][0]) + point->y * ((*m)[0][1]) +
      (point->z) * ((*m)[0][2]) + ((*m)[0][3]);
    res->y = (point->x) * ((*m)[1][0]) + point->y * ((*m)[1][1]) +
      (point->z) * ((*m)[1][2]) + ((*m)[1][3]);
    res->z = (point->x) * ((*m)[2][0]) + point->y * ((*m)[2][1]) +
                (point->z) * ((*m)[2][2]) + ((*m)[2][3]);
    return (res);
}

t_vec3*      matrix4_mult_vec(t_vec3 *res, t_mat4 *m, t_vec3 *vector)
{

    res->x = (vector->x) * ((*m)[0][0]) + (vector->y) * ((*m)[0][1]) +
                (vector->z) * ((*m)[0][2]);
    res->y = (vector->x) * ((*m)[1][0]) + (vector->y) * ((*m)[1][1]) +
                (vector->z) * ((*m)[1][2]);
    res->z = (vector->x) * ((*m)[2][0]) + (vector->y) * ((*m)[2][1]) +
                (vector->z) * ((*m)[2][2]);
    return (res);
}
