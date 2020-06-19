#ifndef PPM_H
#define PPM_H

#include "vec3d.h"

typedef int *ppm_buffer;

void to_stdout(const ppm_buffer);
void ppm_to_file(const ppm_buffer, const char *);
ppm_buffer generate_fake_data();
ppm_buffer generate_gradient_data_from(const vec3d *);

#endif // PPM_H
