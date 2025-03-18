#include "minift.h"

void    da_pop(t_da *da)
{
    da->size -= 1;
    da->capacity += 1;
}

bool    da_realloc(t_da *da)
{
    char*       data;

    data = malloc(da->bytes * da->size * 2);
    if (!data)
        return (false);
    ft_memcpy(data, da->data, (da->size * da->bytes));
    if (da->data)
        free(da->data);
    da->data = data;
    da->capacity = da->size;
    return (true);
}

bool    da_append(t_da *da, void* object)
{
    if (da->capacity == 0 && !da_realloc(da))
        return (false);
    ft_memcpy(da->data + (da->size * da->bytes), object, da->bytes);
    da->size += 1;
    da->capacity -= 1;
    return (true);
}

bool    da_init(t_da *da, size_t capacity, t_bytes bytes)
{
    da->size = 0;
    da->capacity = capacity;
    da->bytes = bytes;
    da->data = malloc(da->bytes * capacity);
    if (!da->data)
        return (false);
    return (true);
}