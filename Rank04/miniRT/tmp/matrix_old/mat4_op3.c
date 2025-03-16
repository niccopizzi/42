#include "matrix.h"

t_mat4*    matrix4_setup_identity(t_mat4 *m)
{
    int row;
    int col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            (*m)[row][col] = (row == col);
            col++;
        }
        row++;
    }
    return (m);
}

t_mat4*    matrix4_setup_scaling(t_mat4 *m, float sx, float sy, float sz)
{
    matrix4_setup_identity(m);
    (*m)[0][0] = sx;
    (*m)[1][1] = sy;
    (*m)[2][2] = sz;
    return (m);
}

t_mat4*    matrix4_transpose(t_mat4 *res, t_mat4 *m)
{
    int row;
    int col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            (*res)[row][col] = (*m)[col][row];
            col++;
        }
        row++;
    }
    return (res);
}

/* 
t_mat4*   matrix4_inverse(t_mat4 *res, t_mat4 *m)
{

} */

/* void    matrix4_setup_transform(t_mat4 *m, t_mat3 rx, t_mat3 ry, t_mat3 rz, float th)
{
    float       costh;
    float       sinth;
    float       onemincosth;

    costh = cosf(th);
    sinth = sinf(th);
    onemincosth = 1 - costh;
    matrix4_setup_identity(m);
    (*m)[0][0] = costh + (rx * rx) * (onemincosth);
    (*m)[0][1] = (rx * ry * onemincosth) - rz * sinth;
    (*m)[0][2] = (rx * rz * onemincosth) + ry * sinth;
    (*m)[1][0] = (ry * rz * onemincosth) + rz * sinth;
    (*m)[1][1] = costh + (ry * ry * onemincosth);
    (*m)[1][2] = (ry * rz * onemincosth) - rx * sinth;
    (*m)[2][0] = (rz * rx * onemincosth) - ry * sinth;
    (*m)[2][1] = (rz * ry * onemincosth) + rz * sinth;
    (*m)[2][2] = costh + (rz * rz * onemincosth);
} */