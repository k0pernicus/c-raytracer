#ifndef RAY_H
#define RAY_H

#include "vec3d.h"

typedef struct ray
{
    vec3d *A;
    vec3d *B;
} ray;

double sphere_hit(const vec3d *, double, const ray *);
double sphere_hit_from_origin(double radius, const ray *r);
vec3d *ray_origin(const ray *);
vec3d *ray_direction(const ray *);
vec3d sphere_get_color(const ray *, double t);
vec3d ray_points_to(const ray *, const double);

#endif // RAY_H
