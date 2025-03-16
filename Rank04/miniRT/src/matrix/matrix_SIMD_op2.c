#include "matrix.h"

t_vec4      matrix4_mult_vec4(t_mat4 m, t_vec4 vec)
{
    return (vector_from_array( (float[]){ 
                vector_dot_product(m[0], vec),
                vector_dot_product(m[1], vec),
                vector_dot_product(m[2], vec),
                vector_dot_product(m[3], vec)
                }));
}

void    matrix4_subm(t_mat3 subm, t_mat4 m, int row, int col)
{
    int i;

    i = 0;
    while (i < 4)
    
}

inline float       matrix2_det(t_mat2 m)
{
    return (m[0] * m[3] - m[2] * m[1]);
}

void    matrix4_print(t_mat4 id)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f ", id[i][j]);
        }
        printf("\n");
    }
}