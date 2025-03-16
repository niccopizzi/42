#ifndef MATRIX_H
#define MATRIX_H

#include "vectors.h"



typedef t_vec4  t_mat4[4];
typedef t_vec4  t_mat3[3];
typedef t_vec4  t_mat2;


void    matrix4_setup_identity(t_mat4 m);


bool        matrix4_compare_eq(t_mat4 m1, t_mat4 m2);
void        matrix4_print(t_mat4 id);
void        matrix4_transpose(t_mat4 m);
void        matrix4_mult_mat4(t_mat4 res, t_mat4 m1, t_mat4 m2);
t_vec4      matrix4_mult_vec4(t_mat4 m, t_vec4 vec);
void        matrix4_copy(t_mat4 dest, t_mat4 src);
#endif   //MATRIX_H

