#include <stdlib.h>
#include "ppm.h"
#include "vec3d.h"

int main(void)
{
    // ppm_buffer buffer = generate_fake_data();
    const vec3d camera = {
        0.0,
        0.0,
        0.0,
    };
    ppm_buffer buffer = generate_gradient_data_from(&camera);
    ppm_to_file(buffer, "output.ppm");
    free(buffer);
    return 0;
}
