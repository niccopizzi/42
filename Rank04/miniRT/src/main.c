#include "miniRT.h"


int main(int argc, char *argv[])
{
    t_ptrs      ptrs;
    t_image     img;
    t_world     world;
    
    t_object sphere = sphere_new(vector_from_array((float[]){0,0,0,1}), 1);
    t_ray    ray = ray_create(vector_from_array((float[]){0,0,5, 1}), vector_from_array((float[]){0,0,1, 0}), PRIMARY);

    ft_bzero(&world, sizeof(t_world));
    if (argc == 1 || !argv[1][0])
        return (printf(ERR NO_FILE), 1);
    if (!da_init(&world.objects, OBJECT_CAPACITY, OBJECT_BYTES))
        return (printf(ERR MALLOC_ERR), 2);
    if (!are_valid_args(argv, &world))
        return(free(world.objects.data), printf("File is not ok!\n"), 3);
    print_world(&world);
    free(world.objects.data);
    //t_ray ray = ray_create(vector_from_array((float[]){2, 3, 4, 1}), vector_normalize(vector_from_array((float[]){1, 0, 0, 0})), PRIMARY);

    t_intersect test;
    sphere_hit_test(&ray, &sphere, &test);
    printf("TEST %f %f %d %d\n", test.t[0], test.t[1], test.count, test.intersected->type);
    connection_init(&ptrs, &img);
    hooks_set_up(&ptrs);
    mlx_clear_window(ptrs.mlx_ptr, ptrs.win_ptr);

    //mlx_put_image_to_window(ptrs.mlx_ptr, ptrs.win_ptr, img.img_ptr, 0, 0);
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
