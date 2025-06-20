/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:25:53 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 15:45:45 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

bool	apply_checker(float u, float v)
{
	int	real_u;
	int	real_v;

	real_u = (int)(10 * u);
	real_v = (int)(5 * v);
	return (((real_u + real_v) % 2) == 0);
}

t_color	color_at_hit(t_shading *info, const t_light *l)
{
	float	lambertian;
	float	specular;
	t_vec4	reflected;
	t_color	ret;

	ret = info->ambient;
	lambertian = fmaxf(0.0f, vector_dot_product(info->normal_at,
				info->light_dir));
	ret += info->obj_hit->color * l->effective * lambertian;
	reflected = vector_reflect(info->light_dir, info->normal_at);
	specular = fmaxf(0.0f, vector_dot_product(info->normal_at, reflected));
	specular = powf(specular, 100);
	ret += info->obj_hit->color * l->effective * specular * 16;
	return (ret);
}

void	get_shading_info(t_shading *shade_info, const t_ray *ray,
		const t_world *world)
{
	shade_info->hitting_ray = ray;
	shade_info->point_hit = ray->direction * shade_info->t + ray->origin;
	shade_info->normal_at = shade_info->obj_hit->normal_get(shade_info->obj_hit,
			shade_info);
	if (vector_dot_product(ray->direction, shade_info->normal_at) >= 0)
	{
		shade_info->normal_at = -shade_info->normal_at;
		shade_info->front_face = false;
	}
	shade_info->ambient = shade_info->obj_hit->color * world->ambient;
}
