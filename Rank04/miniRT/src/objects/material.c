#include "objects.h"

t_material  material_set(float ambient, float diffuse, float specular, float shininess)
{
    t_material  material;

    material.values = vector_from_array((float[]){ambient, diffuse, specular, shininess});
    return (material);
}