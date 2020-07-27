#include "object.h"
#include "sphere.h"
#include <stdio.h>
#include <errno.h>

double hit(const object * obj, const vec3d * vec, double radius) {
    if ((*obj).sphere) {
        return sphere_hit(vec, radius, (ray *) obj->concrete.sphere_ray);
    }
    fprintf(stderr, "Unreachable object");
    perror("Unreachable object - cannot call 'hit' function");
    exit(-1);
}

double hit_from_origin(const object * obj, double radius) {
    if ((*obj).sphere) {
        return sphere_hit_from_origin(radius, (ray *) obj->concrete.sphere_ray);
    }   
    fprintf(stderr, "Unreachable object");
    perror("Unreachable object - cannot call 'hit_from_origin' function");
    exit(-1);
}

vec3d get_color(const object * obj, double t) {
    if ((*obj).sphere) {
        return sphere_get_color((ray *) obj->concrete.sphere_ray, t);
    }
    fprintf(stderr, "Unreachable object");
    perror("Unreachable object - cannot call 'get_color' function");
    exit(-1);
}
