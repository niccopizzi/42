#include <immintrin.h>
#include <x86intrin.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef __m128 t_vec4;

/* inline float   vector_squared_len(t_vec4 *vec)
{
    return (_mm_cvtss_f32(_mm_dp_ps(*vec, *vec, 0xF1)));
}

inline float   vector_len(t_vec4 *vector)
{
    return (sqrtf(vector_squared_len(vector)));
}

t_vec4  vector_normalize(t_vec4 *vector)
{
    float   len;
    
    len = vector_len(vector);
    if (len == 0)
        return (_mm_set1_ps(0));
    return (*vector * (1 / len));
}

void    load_vec(const float *data, t_vec4 *vector)
{
    *vector = _mm_load_ps(data);
}

t_vec4  mult_vec(t_vec4 *vector)
{
    return (*vector * 10);
}

inline bool     vector_in_range(t_vec4 vector, float min, float max)
{
    if ( _mm_movemask_ps(_mm_cmp_ps(vector, _mm_load1_ps(&min), _CMP_LT_OS)) != 0
        || (_mm_movemask_ps(_mm_cmp_ps(vector, _mm_load1_ps(&max), _CMP_GT_OS))))
    {
        return (false);
    }
    return (true);
} */
