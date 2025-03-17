#ifndef MINIRT_H
#define MINIRT_H

#define IMG_RATIO 1.77777
#define WIDTH 1800
#define HEIGHT (int)(WIDTH / IMG_RATIO)
#define OBJECT_CAPACITY 20
#define TO_RAD 0.0174533

#ifndef BONUS
    #define BONUS 1
#endif

#include <time.h>
#include "mlx_utils.h"
#include "parsing.h"
#include "camera.h"
#include "objects.h"
#include "matrix.h"
#endif // MINIRT_H