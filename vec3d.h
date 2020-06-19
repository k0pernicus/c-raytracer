#ifndef VEC3D_H
#define VEC3D_H

#include <math.h>

typedef struct vec3d
{
    double x;
    double y;
    double z;
} vec3d;

inline double vec3d_length(const vec3d *v)
{
    return sqrt((*v).x * (*v).x + (*v).y * (*v).y + (*v).z * (*v).z);
}

inline double vec3d_squared_length(const vec3d *v)
{
    return (*v).x * (*v).x + (*v).y * (*v).y + (*v).z * (*v).z;
}

inline double vec3d_dot(const vec3d *a, const vec3d *b)
{
    return (*a).x * (*b).x + (*a).y * (*b).y + (*a).z * (*b).z;
}

// vec3d
vec3d vec3d_normalize(vec3d *);
vec3d vec3d_minus(const vec3d *);
vec3d vec3d_add(const vec3d *, const vec3d *);
vec3d vec3d_sub(const vec3d *, const vec3d *);
vec3d vec3d_mul_scalar(const vec3d *, const double value);
vec3d vec3d_div(const vec3d *, const vec3d *);

#endif // VEC3D_H
