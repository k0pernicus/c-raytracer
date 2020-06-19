#include "vec3d.h"
#include <math.h>

// C99-11 complient def of inline functions
extern double vec3d_length(const vec3d *v);
extern double vec3d_squared_length(const vec3d *v);
extern double vec3d_dot(const vec3d *a, const vec3d *b);

vec3d vec3d_normalize(vec3d *v)
{
    float k = 1.0 / vec3d_length(v);
    vec3d n_v = {
        k * (*v).x,
        k * (*v).y,
        k * (*v).z,
    };
    return n_v;
}

vec3d minus(const vec3d *v)
{
    vec3d m_v = {-(*v).x, -(*v).y, -(*v).z};
    return m_v;
}

vec3d vec3d_add(const vec3d *a, const vec3d *b)
{
    vec3d a_v = {
        (*a).x + (*b).x,
        (*a).y + (*b).y,
        (*a).z + (*b).z,
    };
    return a_v;
}

vec3d vec3d_sub(const vec3d *a, const vec3d *b)
{
    vec3d s_v = {
        (*a).x - (*b).x,
        (*a).y - (*b).y,
        (*a).z - (*b).z,
    };
    return s_v;
}

vec3d vec3d_mul_scalar(const vec3d *v, const double value)
{
    vec3d m_v = {
        (*v).x * value,
        (*v).y * value,
        (*v).z * value,
    };
    return m_v;
}

vec3d vec3d_div(const vec3d *a, const vec3d *b)
{
    vec3d d_v = {
        (*a).x / (*b).x,
        (*a).y / (*b).y,
        (*a).z / (*b).z,
    };
    return d_v;
}
