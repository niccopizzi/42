#ifndef POINT_H
#define POINT_H


typedef struct s_point2
{
    float   x;
    float   y;
}   t_point2;

typedef struct s_point3
{
    float   x;
    float   y;
    float   z;
}   t_point3;


t_point3*    point_add_vector(t_point3 *res, t_point3 *p, t_vec3 *vec);
t_vec3*      point_sub_point(t_vec3 *res, t_point3 *p1, t_point3 *p2);
t_point3*    lerp(t_point3 *res, t_point3 *p1, t_point3 *p2, float a);

#endif //POINT_H