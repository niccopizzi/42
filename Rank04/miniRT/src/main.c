#include "miniRT.h"

int     convert_to_rgb(t_color* color)
{
    int r = 255.999 * (*color)[0];
    int g = 255.999 * (*color)[1];
    int b = 255.999 * (*color)[2];

    return (r << 16 | g << 8 | b);
}

void    test(t_image *img)
{

    t_da        intersections;
    t_object sphere = sphere_new(vector_from_array((float[]){0,0,0,1}), 1);
    //t_ray    ray = ray_create(vector_from_array((float[]){0, 0, -5, 1}), vector_from_array((float[]){0,0,1, 0}), PRIMARY);

    float   wall_size = 10.0;
    float   pixel_size = wall_size / WIDTH;
    float   max = wall_size * 0.5;

    t_ray ray;
    ray.origin = vector_from_array((float[]){0, 0, -5, 1});
    da_init(&intersections, OBJECT_CAPACITY, INTERSECT_BYTES);
    //sphere_set_transform(&sphere, matrix4_translate(50, 220, 0));
    /* t_intersect* ptrint = (t_intersect *)intersections.data;
    for (size_t i = 0; i < intersections.size; i++)
    {
        printf("T IS %f\n", ptrint[i].t);
    }
    t_intersect* ptr = hit(&intersections); */
    for (int y = 0; y < HEIGHT; y ++)
    {
        float   world_y = max -  pixel_size * y;   
        for (int x = 0; x <  WIDTH; x++)
        {
            float   world_x = - max + pixel_size * x;
            ray.direction = vector_from_array((float[]){world_x, world_y, 10, 0}) - ray.origin;
            ray.direction = vector_normalize(ray.direction);
            if (sphere_hit_test(&ray, &sphere, &intersections))
                image_pixel_put(img, x, y, convert_to_rgb(&sphere.color));
        }
    }
    free(intersections.data);
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
    //print_world(&world);
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
