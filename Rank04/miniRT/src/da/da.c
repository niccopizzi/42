#include "da.h"

void    objects_pop(t_objects_da *objs)
{
    objs->size -= 1;
    objs->capacity += 1;
}

void    objects_swap(t_objects_da *objs, int pos1, int pos2)
{
    t_object temp;

    if (pos1 >= (objs->size) || pos2 >= (objs->size))
    {
        printf("Error: index out ouf range\n");
        return;
    }
    temp = objs->list[pos2];
    objs->list[pos2] = objs->list[pos1];
    objs->list[pos1] = temp;   
}

bool    objects_realloc(t_objects_da *objs)
{
    int         i;
    t_object*   list;

    list = malloc(sizeof(t_object) * objs->size * 2);
    if (!list)
        return (false);
    i = 0;
    while (i < objs->size)
    {
        list[i] = objs->list[i];
        i++;
    }
    if (objs->list)
        free(objs->list);
    objs->list = list;
    objs->capacity = objs->size;
    return (true);
}

bool    objects_append(t_objects_da *objs, t_object object)
{
    if (objs->capacity == 0 && !objects_realloc(objs))
        return (false);
    objs->list[objs->size] = object;
    objs->size += 1;
    objs->capacity -= 1;
    return (true);
}

bool    objects_init(t_objects_da *objs, int capacity)
{
    objs->size = 0;
    objs->capacity = capacity;
    objs->list = malloc(sizeof(t_object) * capacity);
    if (!objs->list)
        return (false);
    return (true);
}