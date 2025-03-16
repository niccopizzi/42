#include "matrix.h"

t_mat3* matrix3_mult_mat3(t_mat3 *res, t_mat3 *m1, t_mat3 *m2)
{
    int     row;
    int     col;

    row = 0;
    while (row < 3)
    {
        col = 0;
        while (col < 3)
        {
            (*res)[row][col] = (*m1)[row][0] * (*m2)[0][col] +  
                                (*m1)[row][1] * (*m2)[1][col] +
                                (*m1)[row][2] * (*m2)[2][col];
            col++;
        }
        row++;
    }
    return (res);
}

t_mat3*    matrix3_setup_identity(t_mat3 *m)
{
    int row;
    int col;

    row = 0;
    while (row < 3)
    {
        col = 0;
        while (col < 3)
        {
            (*m)[row][col] = (row == col);
            col++;
        }
        row++;
    }
    return (m);
}

t_mat3*    matrix3_setup_rx(t_mat3 *m, float th)
{
    float   costh;
    float   sinth;

    matrix3_setup_identity(m);
    costh = cosf(th);
    sinth = sinf(th);
    (*m)[1][1] = costh;
    (*m)[1][2] = sinth;
    (*m)[2][1] = -sinth;
    (*m)[2][2] = costh;
    return (m);
}


t_mat3*    matrix3_setup_ry(t_mat3 *m, float th)
{
    float   costh;
    float   sinth;

    matrix3_setup_identity(m);
    costh = cosf(th);
    sinth = sinf(th);
    (*m)[0][0] = costh;
    (*m)[0][2] = -sinth;
    (*m)[2][0] = sinth;
    (*m)[2][2] = costh;
    return (m);
}

t_mat3*    matrix3_setup_rz(t_mat3 *m, float th)
{
    float   costh;
    float   sinth;

    matrix3_setup_identity(m);
    costh = cosf(th);
    sinth = sinf(th);
    (*m)[0][0] = costh;
    (*m)[0][1] = sinth;
    (*m)[1][0] = -sinth;
    (*m)[1][1] = costh;
    return (m);
}