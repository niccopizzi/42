#include "miniRT.h"
/* 
void        camera_setup(t_cam *camera)
{

    if (camera->forward.x == 0.f && camera->forward.z == 0.f &&
        (camera->forward.y == -1.f || camera->forward.y == 1.f))
    {
        camera->up = (t_vec3){0, 0, -(camera->forward.y)};
        camera->right = (t_vec3){1, 0, 0};
        return;
    }
    vector_cross_prod(&camera->right, &(t_vec3 ){0, 1, 0}, &camera->forward);
    vector_cross_prod(&camera->up, &camera->forward, &camera->right);
    vector_normalize(&camera->right, &camera->right);
    vector_normalize(&camera->up, &camera->up);
}

t_mat4*     camera_look_at(t_mat4* m, t_cam *cam)
{
    (*m)[0][0] = cam->right.x;
    (*m)[0][1] = cam->right.y;
    (*m)[0][2] = cam->right.z;
    (*m)[1][0] = cam->up.x;
    (*m)[1][1] = cam->up.y;
    (*m)[1][2] = cam->up.z;
    (*m)[2][0] = cam->forward.x;
    (*m)[2][1] = cam->forward.y;
    (*m)[2][2] = cam->forward.z;
    (*m)[3][0] = cam->origin.x;
    (*m)[3][1] = cam->origin.y;
    (*m)[3][2] = cam->origin.z;

    return (m);
}

t_point3    camera_pixel_get(int x, int y, float zoom)
{
    t_point3    camera_pixel;

    camera_pixel.x = (2 * ((x + 0.5) / WIDTH) - 1) * zoom * IMG_RATIO;
    camera_pixel.y = (1 - 2 * (y + 0.5) / HEIGHT) * zoom;
    camera_pixel.z = -1;

    return (camera_pixel);
}


t_ray       camera_ray_get(t_cam *camera, t_point3 *camera_pixel)
{
    t_ray   camera_ray;

    camera_ray.origin = camera->origin;
    point_sub_point(&camera_ray.direction, camera_pixel, &camera->origin);
    vector_normalize(&camera_ray.direction, &camera_ray.direction);
    return (camera_ray);
} */
