#include "sphere.h"
#include "../vec3d.h"
#include "../ray.h"
#include "object.h"

object new_sphere(const ray *r) {
    object o;
    o.sphere = 1;
    o.concrete.sphere_ray = r;
    return o;
}

static vec3d sphere_origin = {0., 0., -1.};

double sphere_hit(const vec3d *sphere_origin, double radius, const ray *r)
{
    vec3d oc = vec3d_sub(ray_origin(r), sphere_origin);
    // a => ray_direction(r) . ray_direction(r)
    double a = vec3d_squared_length(ray_direction(r));
    double half_b = vec3d_dot(&oc, ray_direction(r));
    double c = vec3d_squared_length(&oc) - (radius * radius);
    double discriminant = (half_b * half_b) - (a * c);
    if (discriminant < 0.)
    {
        return -1.;
    }
    return (-half_b - sqrt(discriminant)) / a;
}

double sphere_hit_from_origin(double radius, const ray *r) {
    return sphere_hit(&sphere_origin, radius, r);
}

vec3d sphere_get_color(const ray *r, double t)
{
    // Sphere has been hitten
    if (t > 0.0)
    {
        // Compute the right color
        vec3d drawed_ray_t = ray_points_to(r, t);
        vec3d subbed_ray_t = vec3d_sub(&drawed_ray_t, &(vec3d){0., 0., -1.});
        vec3d N = vec3d_normalize(&subbed_ray_t);
        // Return the sphere associated to the right color
        return vec3d_mul_scalar(&(vec3d){N.x + 1, N.y + 1, N.z + 1}, 0.5);
    }
    vec3d unit_direction = vec3d_normalize(ray_direction(r));
    t = 0.5 * (unit_direction.y + 1.0);
    const vec3d one_vec = {
        1.0,
        1.0,
        1.0,
    };
    const vec3d norm_v = {
        0.5,
        0.7,
        1.0};
    const vec3d blended_start_v = vec3d_mul_scalar(&one_vec, 1.0 - t);
    const vec3d blended_end_v = vec3d_mul_scalar(&norm_v, t);
    return vec3d_add(&blended_start_v, &blended_end_v);
}