/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_SIMD_op1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:19:39 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:19:40 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

inline t_mat4	matrix4_identity(void)
{
	t_mat4	m;

	m.row[0] = (t_vec4){1, 0, 0, 0};
	m.row[1] = (t_vec4){0, 1, 0, 0};
	m.row[2] = (t_vec4){0, 0, 1, 0};
	m.row[3] = (t_vec4){0, 0, 0, 1};
	return (m);
}

inline bool	matrix4_compare_eq(const t_mat4 *m1, const t_mat4 *m2)
{
	return (vector_compare_eq(m1->row[0], m2->row[0])
		&& vector_compare_eq(m1->row[1], m2->row[1])
		&& vector_compare_eq(m1->row[2], m2->row[2])
		&& vector_compare_eq(m1->row[3], m2->row[3]));
}

t_mat4	matrix4_transpose(t_mat4 m)
{
	_MM_TRANSPOSE4_PS(m.row[0], m.row[1], m.row[2], m.row[3]);
	return (m);
}

inline void	matrix4_copy(t_mat4 *dest, const t_mat4 *src)
{
	dest->row[0] = src->row[0];
	dest->row[1] = src->row[1];
	dest->row[2] = src->row[2];
	dest->row[3] = src->row[3];
}

t_mat4	matrix4_mult_mat4(const t_mat4 *m1, const t_mat4 *m3)
{
	t_mat4	m2;
	t_mat4	res;

	matrix4_copy(&m2, m3);
	_MM_TRANSPOSE4_PS(m2.row[0], m2.row[1], m2.row[2], m2.row[3]);
	(res).row[0] = (t_vec4){vector_dot_product(m1->row[0], m2.row[0]),
		vector_dot_product(m1->row[0], m2.row[1]),
		vector_dot_product(m1->row[0], m2.row[2]),
		vector_dot_product(m1->row[0], m2.row[3])};
	(res).row[1] = (t_vec4){vector_dot_product(m1->row[1], m2.row[0]),
		vector_dot_product(m1->row[1], m2.row[1]),
		vector_dot_product(m1->row[1], m2.row[2]),
		vector_dot_product(m1->row[1], m2.row[3])};
	(res).row[2] = (t_vec4){vector_dot_product(m1->row[2], m2.row[0]),
		vector_dot_product(m1->row[2], m2.row[1]),
		vector_dot_product(m1->row[2], m2.row[2]),
		vector_dot_product(m1->row[2], m2.row[3])};
	(res).row[3] = (t_vec4){vector_dot_product(m1->row[3], m2.row[0]),
		vector_dot_product(m1->row[3], m2.row[1]),
		vector_dot_product(m1->row[3], m2.row[2]),
		vector_dot_product(m1->row[3], m2.row[3])};
	return (res);
}
