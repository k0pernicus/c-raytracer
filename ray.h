#ifndef RAY_H
#define RAY_H

#include "vec3d.h"

typedef struct ray
{
    vec3d *A;
    vec3d *B;
} ray;

double hit_sphere(const vec3d *, double, const ray *);
vec3d *ray_origin(const ray *);
vec3d *ray_direction(const ray *);
vec3d ray_get_color(const ray *);
vec3d ray_points_to(const ray *, const double);

#endif // RAY_H
