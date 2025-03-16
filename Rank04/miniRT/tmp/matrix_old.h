#ifndef MATRIX_H
#define MATRIX_H

#include "vectors.h"
#include <stdio.h>

typedef float   t_mat4[4][4];
typedef float   t_mat3[3][3];

t_mat4*     matrix4_mult_scalar(t_mat4 *res, t_mat4 *m1, float scalar);
t_mat4*     matrix4_add_scalar(t_mat4 *res, t_mat4 *m1, float scalar);
t_mat4*     matrix4_transpose(t_mat4 *res, t_mat4 *m);
t_mat4*     matrix4_mult_mat4(t_mat4 *res, t_mat4 *m1, t_mat4 *m2);
t_mat4*     matrix4_sub_mat4(t_mat4 *res, t_mat4 *m1, t_mat4 *m2);
t_mat4*     matrix4_add_mat4(t_mat4 *res, t_mat4 *m1, t_mat4 *m2);


t_vec3*      matrix4_mult_vec(t_vec3 *res, t_mat4 *m, t_vec3 *vector);
t_point3*    matrix4_mult_point(t_point3 *res, t_mat4 *m, t_point3 *point);


t_mat4*    matrix4_setup_transform(t_mat4 *m, float rx, float ry, float rz, float th);
t_mat4*    matrix4_setup_identity(t_mat4 *m);
t_mat4*    matrix4_setup_scaling(t_mat4 *m, float sx, float sy, float sz);
void    matrix4_print(t_mat4 *m);




t_mat3*    matrix3_mult_mat3(t_mat3 *res, t_mat3 *m1, t_mat3 *m2);
t_mat3*    matrix3_setup_identity(t_mat3 *m);
t_mat3*    matrix3_setup_rx(t_mat3 *m, float th);
t_mat3*    matrix3_setup_ry(t_mat3 *m, float th);
t_mat3*    matrix3_setup_rz(t_mat3 *m, float th);

#endif  //MATRIX_H