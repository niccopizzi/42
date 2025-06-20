/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:23:08 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:36:01 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

bool	plane_hit(const t_object *pl, const t_ray *r, double *t_min)
{
	double	dotprod;

	dotprod = vector_dot_product(r->direction, pl->normal);
	if (dotprod == 0.0)
	{
		return (false);
	}
	return (check_t(vector_dot_product(pl->point - r->origin, pl->normal)
			/ dotprod, t_min));
}

bool	disk_hit(const t_object *ds, const t_ray *r, double *t_min)
{
	double	dotprod;
	double	t;

	dotprod = vector_dot_product(r->direction, ds->normal);
	if (dotprod == 0.0)
		return (false);
	t = vector_dot_product(ds->point - r->origin, ds->normal) / dotprod;
	if (t > EPSILON)
	{
		if (vector_len_squared(ray_at(r, t) - ds->point) <= ds->r2)
		{
			*t_min = t;
			return (true);
		}
		return (false);
	}
	return (false);
}

bool	sphere_hit(const t_object *sp, const t_ray *r, double *t_min)
{
	t_sp_equation	v;
	t_vec4			oc;

	oc = r->origin - sp->point;
	v.a = vector_dot_product(r->direction, r->direction);
	v.b = 2.0 * (vector_dot_product(r->direction, oc));
	v.c = vector_dot_product(oc, oc) - sp->r2;
	v.discr = v.b * v.b - (4.0 * v.a * v.c);
	if (v.discr < 0)
		return (false);
	v.discr = sqrt(v.discr);
	v.denom = 1.0 / (2.0 * v.a);
	v.t = (-v.b - v.discr) * v.denom;
	if (check_t(v.t, t_min))
		return (true);
	v.t = (-v.b + v.discr) * v.denom;
	return (check_t(v.t, t_min));
}

bool	cylinder_hit(const t_object *cy, const t_ray *r, double *t_min)
{
	t_point4		hit_point;
	double			t;
	t_cy_equation	eq;

	eq.x = r->origin - cy->point;
	eq.dv = vector_dot_product(r->direction, cy->axis);
	eq.xv = vector_dot_product(eq.x, cy->axis);
	eq.a = vector_dot_product(r->direction, r->direction) - eq.dv * eq.dv;
	eq.b = vector_dot_product(r->direction, eq.x) - eq.dv * eq.xv;
	eq.c = vector_dot_product(eq.x, eq.x) - eq.xv * eq.xv - cy->r2;
	eq.discr = eq.b * eq.b - eq.a * eq.c;
	if (eq.discr < 0)
		return (false);
	eq.discr = sqrt(eq.discr);
	t = (-eq.b - eq.discr) / eq.a;
	hit_point = ray_at(r, t);
	if (is_inside_cy(hit_point, cy) && check_t(t, t_min))
		return (true);
	t = (-eq.b + eq.discr) / eq.a;
	hit_point = ray_at(r, t);
	return (is_inside_cy(hit_point, cy) && check_t(t, t_min));
}

bool	cone_hit(const t_object *co, const t_ray *r, double *t_min)
{
	double			t;
	double			k2;
	t_co_equation	eq;
	t_point4		hit_point;

	k2 = (co->k * co->k) + 1;
	eq.x = r->origin - co->point;
	eq.dv = vector_dot_product(r->direction, co->axis);
	eq.xv = vector_dot_product(eq.x, co->axis);
	eq.a = vector_dot_product(r->direction, r->direction) - k2 * (eq.dv
			* eq.dv);
	eq.b = vector_dot_product(r->direction, eq.x) - k2 * eq.dv * eq.xv;
	eq.c = vector_dot_product(eq.x, eq.x) - eq.xv * eq.xv * k2;
	eq.discr = eq.b * eq.b - eq.a * eq.c;
	if (eq.discr < 0)
		return (false);
	eq.discr = sqrt(eq.discr);
	t = (-eq.b - eq.discr) / eq.a;
	hit_point = ray_at(r, t);
	if (is_inside_co(hit_point, co) && check_t(t, t_min))
		return (true);
	t = (-eq.b + eq.discr) / eq.a;
	hit_point = ray_at(r, t);
	return (is_inside_co(hit_point, co) && check_t(t, t_min));
}
