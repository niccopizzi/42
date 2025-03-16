#include "vectors.h"

inline t_vec4  vector_normalize(t_vec4 vector)
{
    float   len;
    
    len = vector_len(vector);
    if (len == 0)
        return (_mm_set1_ps(0));
    return (vector * (1 / len));
}

inline  t_vec4      vector_cross_prod(t_vec4 vector1, t_vec4 vector2)
{
    t_vec4 tmp0;
    t_vec4 tmp1;
    t_vec4 tmp2;
    t_vec4 tmp3;
    t_vec4 tmp4;

    tmp0 = _mm_shuffle_ps(vector1, vector2, _MM_SHUFFLE(3,0,2,1) );
	tmp1 = _mm_shuffle_ps(vector1, vector2, _MM_SHUFFLE(3,1,0,2) );
	tmp2 = _mm_mul_ps(tmp0, vector1);
	tmp3 = _mm_mul_ps(tmp0, tmp1);
	tmp4 = _mm_shuffle_ps(tmp2, tmp2, _MM_SHUFFLE(3,0,2,1));
	return (_mm_sub_ps(tmp3, tmp4));
}

inline t_point4    lerp(t_point4 p1, t_point4 p2, float a)
{   
    return (_mm_add_ps(p1 * (1 - a), p2 * (a)));
}    

inline bool     vector_in_range(t_vec4 vector, float min, float max)
{
    return ((_mm_movemask_ps(_mm_cmp_ps(vector, _mm_load1_ps(&min),
         _CMP_LT_OS))) == 0 && _mm_movemask_ps(_mm_cmp_ps(vector, 
         _mm_load1_ps(&max), _CMP_GT_OS)) == 0);
}