/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:25:36 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:25:37 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

inline t_ray	ray_create(t_point4 origin, t_vec4 direction, t_rtype type)
{
	t_ray	ray;

	ray.type = type;
	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

inline t_point4	ray_at(const t_ray *ray, float time)
{
	return (vector_at(ray->origin, ray->direction, time));
}

t_ray	ray_transform(const t_ray *ray, const t_mat4 *tm)
{
	t_ray	ray_transform;

	ray_transform.type = ray->type;
	ray_transform.origin = matrix4_mult_vec4(tm, ray->origin);
	ray_transform.direction = matrix4_mult_vec4(tm, ray->direction);
	return (ray_transform);
}

t_ray	ray_refract(const t_ray *ray, const t_vec4 normal, t_point4 p,
		float ratio)
{
	t_ray	refracted_ray;

	refracted_ray.type = REFRACTIVE;
	refracted_ray.origin = p;
	refracted_ray.direction = vector_refract(ray->direction, normal, ratio);
	return (refracted_ray);
}

t_ray	ray_reflect(const t_ray *ray, const t_vec4 normal, t_point4 p)
{
	t_ray	reflected_ray;

	reflected_ray.type = REFLECTIVE;
	reflected_ray.origin = p;
	reflected_ray.direction = vector_reflect(ray->direction, normal);
	return (reflected_ray);
}
