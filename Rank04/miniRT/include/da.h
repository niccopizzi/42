#ifndef DA_H
#define DA_H

#include <stdbool.h>
#include <stdio.h>
#include "objects.h"

typedef struct s_objects_da
{
    t_object* list;
    int       size;
    int       capacity;
} t_objects_da;


bool    objects_realloc(t_objects_da *objs);
bool    objects_append(t_objects_da *objs, t_object object);
bool    objects_init(t_objects_da *objs, int capacity);
void    objects_pop(t_objects_da *objs);
void    objects_swap(t_objects_da *objs, int pos1, int pos2);

#endif  //DA_H