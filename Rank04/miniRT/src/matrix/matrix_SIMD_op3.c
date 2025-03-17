#include "matrix.h"

t_mat4      matrix4_shearing(const float* values)
{
    t_mat4  m;

    m.row[0] = vector_from_array((float[]){1, values[0], values[1], 0});
    m.row[1] = vector_from_array((float[]){values[2], 1, values[3], 0});
    m.row[2] = vector_from_array((float[]){values[4], values[5], 1, 0});
    m.row[3] = vector_from_array((float[]){0, 0, 0, 1});

    return (m);
}

t_mat4      matrix4_translate(float tx, float ty, float tz)
{
    t_mat4  m;

    m = matrix4_identity();
    m.row[0][3] = tx;
    m.row[1][3] = ty;
    m.row[2][3] = tz;

    return (m);
}

t_mat4      matrix4_scaling(float tx, float ty, float tz)
{
    t_mat4  m;

    m = matrix4_identity();
    m.row[0][0] = tx;
    m.row[1][1] = ty;
    m.row[2][2] = tz;

    return (m);
}

t_mat4      matrix4_rotate_x(float  rad)
{
    t_mat4  m;
    float   sinr;
    float   cosr;

    m = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.row[1] = vector_from_array((float[]){0, cosr, -sinr, 0});
    m.row[2] = vector_from_array((float[]){0, sinr, cosr, 0});

    return (m);
}

t_mat4      matrix4_rotate_y(float rad)
{
    t_mat4  m;
    float   sinr;
    float   cosr;

    m = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.row[0] = vector_from_array((float[]){cosr, 0, sinr, 0});
    m.row[2] = vector_from_array((float[]){-sinr, 0, cosr, 0});

    return (m);
}

t_mat4      matrix4_rotate_z(float rad)
{
    t_mat4  m;
    float   sinr;
    float   cosr;

    m = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.row[0] = vector_from_array((float[]){cosr, -sinr, 0, 0});
    m.row[1] = vector_from_array((float[]){sinr, cosr, 0, 0});

    return (m);
}