#include "matrix.h"

t_mat4*     matrix4_add_mat4(t_mat4 *res, t_mat4 *m1, t_mat4 *m2)
{
    int         row;
    int         col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            (*res)[row][col] = (*m1)[row][col] + (*m2)[row][col];
            col++;
        }
        row++;
    }
    return (res);
}

t_mat4*     matrix4_sub_mat4(t_mat4 *res, t_mat4 *m1, t_mat4 *m2)
{
    int         row;
    int         col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            (*res)[row][col] = (*m1)[row][col] - (*m2)[row][col];
            col++;
        }
        row++;
    }
    return (res);
}

t_mat4*     matrix4_add_scalar(t_mat4 *res, t_mat4 *m1, float scalar)
{
    int         row;
    int         col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            (*res)[row][col] = (*m1)[row][col] + scalar;
            col++;
        }
        row++;
    }
    return (res);
}

void    matrix4_print(t_mat4 *m)
{
    int row;
    int col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            printf("%f ", (*m)[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
    printf("\n");
}