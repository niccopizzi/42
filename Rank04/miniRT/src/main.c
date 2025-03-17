#include "miniRT.h"

float hit_sphere(t_ray *ray, t_object *obj)
{
    t_vec4  oc;
    bool    inside;
    float   lensq;
    float   tca;
    float   t2hc;
    float   r2;

    r2 = obj->diameter * 0.5 * obj->diameter * 0.5;
    oc = ray->direction - obj->center;
    lensq = vector_len_squared(oc);
    inside = lensq < r2;
    tca = vector_dot_product(oc, ray->direction);
    if (tca < 0 && !inside)
        return (0);
    t2hc = r2 - (lensq - (tca * tca));
    if (t2hc < 0)
        return (0);
    if (inside)
        return (tca + sqrt(t2hc));
    return (tca - sqrt(t2hc));
}

int main(int argc, char *argv[])
{
    t_ptrs      ptrs;
    t_image     img;
    t_world     world;
    
    t_point4    p = vector_from_array((float[]){0, 1, 0, 1});

    t_mat4      rotate = matrix4_rotate_z(PI / 12);

    t_mat4      t_m = matrix4_mult_mat4(matrix4_translate(200, 200, 0), rotate);
    ft_bzero(&world, sizeof(t_world));
    if (argc == 1 || !argv[1][0])
        return (printf(ERR NO_FILE), 1);
    if (!objects_init(&world.objects, OBJECT_CAPACITY))
        return (printf(ERR MALLOC_ERR), 2);
    if (!are_valid_args(argv, &world))
        return(printf("File is not ok!\n"), 3);
    free(world.objects.list);
    connection_init(&ptrs, &img);
    hooks_set_up(&ptrs);
    mlx_clear_window(ptrs.mlx_ptr, ptrs.win_ptr);
    for (int i = 0; i < 12; i++)
    {
        int     px = WIDTH * 0.5 + (WIDTH * 0.5) * p[0];
        int     py = HEIGHT * 0.5 + (HEIGHT * 0.5) * p[1];
        for (int x = 0; x <= 25; x++)
        {
            for (int y = 0; y <= 25; y++)
            {
                if (x * x + y *y <= 100)
                    image_pixel_put(&img, px + x, py + y, 0xFFFFFF);
            }
        }
        p = matrix4_mult_vec4(rotate, p);
    }
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


/* void    print_obj(t_world world, t_objects_da *objs)
{
    t_object* ptr;


    printf("\n\nWORLD AM LIGHT\nratio: %f\nrgb: %d %d %d\n\n", world.a_light.ratio, world.a_light.color.r, world.a_light.color.g, world.a_light.color.b);
    printf("\n\nWORLD CAMERA\ncoor: %f %f %f\nvec: %f %f %f\nfov: %f\n\n", world.cam.origin.x, world.cam.origin.y, world.cam.origin.z, world.cam.d.x, world.cam.d.y, world.cam.d.z, world.cam.fov);
    printf("\n\nWORLD LIGHT\ncoor: %f %f %f\nratio: %f\nrgb %d %d %d\n\n", world.light_src.pos.x, world.light_src.pos.y, world.light_src.pos.z, world.light_src.brightness, world.light_src.color.r, world.light_src.color.g, world.light_src.color.b);
    ptr = objs->list;
    for(int i = 0; i < objs->size; i++)
    {
        switch (ptr[i].type)
        {
        case SP:
            printf("\n\nSPHERE\nCENTER: %f %f %f\nDIAMETER: %f\nRGB: %d %d %d\n", 
            ptr[i].center.x,ptr[i].center.y,ptr[i].center.z,
            ptr[i].diameter, ptr[i].color.r, ptr[i].color.g, ptr[i].color.b);
            break;
        case PL:
            printf("\n\nPLANE\nPOINT: %f %f %f\nNORMAL %f %f %f\nRGB: %d %d %d\n", ptr[i].point.x, ptr[i].point.y, ptr[i].point.z, 
            ptr[i].normal.x,ptr[i].normal.y, ptr[i].normal.z, 
            ptr[i].color.r, ptr[i].color.g,  ptr[i].color.b);
            break;
        case CY:
            printf("\n\nCYLINDER\nCENTER: %f %f %f\nAXIS: %f %f %f\nDIAMETER: %f\nHEIGHT: %f\nRGB: %d %d %d\n", ptr[i].center.x, ptr[i].center.y, ptr[i].center.z,
            ptr[i].axis.x, ptr[i].axis.y, ptr[i].axis.z, ptr[i].diameter, ptr[i].height, ptr[i].color.r, ptr[i].color.g, ptr[i].color.b);
            break;
        default:
            printf("ERROR   \n");
            break;
        }
    }
} */