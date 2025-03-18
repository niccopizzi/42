#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "objects.h"
#include "../lib/minift/include/minift.h"

typedef struct s_intersect
{
    float       t[2];
    int         count;   
    t_object*   intersected;
     
}   t_intersect;

#endif  //INTERSECTIONS_H