#include "ray.h"
#include "vec3d.h"

vec3d *ray_origin(const ray *r) { return r->A; }
vec3d *ray_direction(const ray *r) { return r->B; }
vec3d ray_points_to(const ray *r, const double value)
{
    const vec3d mul_t = vec3d_mul_scalar(r->B, value);
    return vec3d_add(r->A, &mul_t);
}
