#ifndef OBJECTS
#define OBJECTS

#include "../ray.h"
#include "../vec3d.h"

typedef struct object {
    unsigned sphere : 1;
    union
    {
        void* sphere_ray;
    } concrete;
} object;

double hit(const object *, const vec3d *, double);
double hit_from_origin(const object *, double radius);
vec3d get_color(const object *, double t);

#endif // OBJECTS