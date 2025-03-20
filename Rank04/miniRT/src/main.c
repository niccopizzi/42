/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:29:48 by npizzi            #+#    #+#             */
/*   Updated: 2025/03/20 19:14:26 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float   clamp(float to_clamp, float min, float max)
{
    if (to_clamp < min)
        return (min);
    if (to_clamp > max)
        return (max);
    return (to_clamp);
}

int     convert_to_rgb(t_color* color)
{
    int r = 255.999 * (*color)[0];
    int g = 255.999 * (*color)[1];
    int b = 255.999 * (*color)[2];
    return (r << 16 | g << 8 | b);
}

t_color   lightning(t_material* material, t_point4 *p, t_light* light, t_vec4* eye, t_vec4* normal, t_color color)
{
    t_color     ambient;
    t_color     effective;
    t_color     diffuse;
    t_vec4      reflected_ray;
    t_vec4      light_vector;
    float       dotprod;
    
    effective = color * light->brightness;
    light_vector = vector_normalize(light->pos - *p);
    ambient = material->elem.ambient * effective;
    dotprod = vector_dot_product(light_vector, *normal);
    if (dotprod < 0)
        return (ambient);
    diffuse = effective * material->elem.diffuse * dotprod;
    reflected_ray = vector_reflect(-light_vector, *normal);
    float lenlv = vector_len(reflected_ray); 
    if (lenlv < 1.0f - EPSILON || lenlv > 1.0f + EPSILON)
        printf("reflected ray len is not 1 and is %f\n", lenlv);
    float   reflectdotprod = vector_dot_product(reflected_ray, *eye);
    if (reflectdotprod <= 0)
        return (ambient + diffuse);
    float factor = powf(reflectdotprod, material->elem.shininess);
    float   specular_val = light->brightness * material->elem.specular * factor;
    t_color specular = vector_from_float(specular_val);
    return (ambient + diffuse + specular);
}

void    test(t_image *img)
{

    t_primitive sphere_primitive;
    t_object sphere = sphere_new(vector_from_array((float[]){0,0,0,1}), 1);
    t_light light;
    //t_ray    ray = ray_create(vector_from_array((float[]){0, 0, -5, 1}), vector_from_array((float[]){0,0,1, 0}), PRIMARY);

    light.pos = vector_from_array((float[]){0, 0, 10, 1});
    light.brightness = 1;
    float   wall_size = 10.0;
    float   pixel_size = wall_size / WIDTH;
    float   max = wall_size * 0.5;
    
    t_material m = material_set(0.9, 0.3, 0.7, 200.0);
    sphere.color = vector_from_array((float[]){1, 1, 1, 0});
    t_ray ray;
    ray.origin = vector_from_array((float[]){0, 0, -7, 1});
    sphere_primitive.material = &m;
    sphere_primitive.object = &sphere;
    //sphere.transform = matrix4_scaling(2, 0.5, 1);
    //sphere.transform = matrix4_invert(sphere.transform);
    float   interesections[2];
    for (int y = 0; y < HEIGHT; y ++)
    {
        float   world_y = max -  pixel_size * y;   
        for (int x = 0; x <  WIDTH; x++)
        {
            float   world_x = - max + pixel_size * x;
            ray.direction = vector_from_array((float[]){world_x, world_y, 10, 0}) - ray.origin;
            ray.direction = vector_normalize(ray.direction);
            if (sphere_hit_test(&ray, &sphere, interesections))
            {
                float       t = fmin(interesections[0], interesections[1]);
                if (t >= 0)
                {
                    t_point4    p = ray_at(ray, t);
                    t_vec4      normal = sphere_normal_at(&sphere, &p);
                    t_vec4      eye = -ray.direction;
                    t_color     color = lightning(sphere_primitive.material, &p, &light, 
                    &eye, &normal, sphere.color);
                    color[0] = clamp(color[0], 0, 1);
                    color[1] = clamp(color[1], 0, 1);
                    color[2] = clamp(color[2], 0, 1);
                    image_pixel_put(img, x, y, convert_to_rgb(&color));
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    t_ptrs      ptrs;
    t_image     img;
    t_world     world;

    ft_bzero(&world, sizeof(t_world));
    if (argc == 1 || !argv[1][0])
        return (printf(ERR NO_FILE), 1);
    if (!da_init(&world.objects, OBJECT_CAPACITY, OBJECT_BYTES))
        return (printf(ERR MALLOC_ERR), 2);
    if (!are_valid_args(argv, &world))
        return(free(world.objects.data), printf("File is not ok!\n"), 3);
    free(world.objects.data);
    
    connection_init(&ptrs, &img);
    hooks_set_up(&ptrs);
    mlx_clear_window(ptrs.mlx_ptr, ptrs.win_ptr);

    test(&img);
    mlx_put_image_to_window(ptrs.mlx_ptr, ptrs.win_ptr, img.img_ptr, 0, 0);
    mlx_loop(ptrs.mlx_ptr);
    return (0);
}

/*



int convert_color(t_color *pixel_color)
{

    int rbyte = (int)(255.999 * pixel_color->r);
    int gbyte = (int)(255.999 * pixel_color->g);
    int bbyte = (int)(255.999 * pixel_color->b);

    return (rbyte << 16 | gbyte << 8 | bbyte);
} */
