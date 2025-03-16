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
    t_mat4      m;
    t_mat4      id;
    t_mat4      res;
    t_vec4      vec;

    m[0] = vector_from_array((float[]){1,2,3,4});
    m[1] = vector_from_array((float[]){2,4,4,2});
    m[2] = vector_from_array((float[]){8,3,4,1});
    m[3] = vector_from_array((float[]){0,0,0,1});

    vec = vector_from_array((float[]){1,2,3,1});

    vec = matrix4_mult_vec4(m , vec);
    printf("VECTOR IS NOW %f %f %f %f\n", vec[0], vec[1], vec[2], vec[3]);
    printf("\t\t\tMAT IS \n");
    matrix4_print(m);
    

    matrix4_setup_identity(id);
    matrix4_mult_mat4(res, m, id);
    printf("\t\t\tMAT IS NOW\n");
    matrix4_print(m);
    vec = matrix4_mult_vec4(id , vec);
    printf("VECTOR IS NOW %f %f %f %f\n", vec[0], vec[1], vec[2], vec[3]);
    matrix4_transpose(id);
    printf("\t\t\tID IS\n");
    matrix4_print(id);
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