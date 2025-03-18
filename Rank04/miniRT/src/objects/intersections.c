#include "objects.h"

t_intersect*    hit(const t_da *intersections)
{
    t_intersect*    it;
    size_t          size;
    size_t          n;
    t_intersect*    closest;

    n = intersections->size;
    if (!n)
        return (NULL);
    it = (t_intersect *)intersections->data;
    closest = it;
    size = 0;
    while (size < n)
    {
        if (it[size].t > 0 && it[size].t < closest->t)
            closest = it;
        size++;
    }
    if (closest->t < 0)
        return (NULL);
    return (closest);
}