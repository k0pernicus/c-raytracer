#ifndef OBJ_SPHERE
#define OBJ_SPHERE

#include "../vec3d.h"
#include "../ray.h"

double sphere_hit(const vec3d *, double, const ray *);
double sphere_hit_from_origin(double radius, const ray *r);
vec3d sphere_get_color(const ray *, double t);

#endif // OBJ_SPHERE