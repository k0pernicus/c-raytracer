#include <stdlib.h>
#include "ppm.h"
#include "vec3d.h"

const char* DEFAULT_OUTPUT_NAME = "output.ppm";

int main(int argc, char* argv[])
{
    char* ppm_filename = DEFAULT_OUTPUT_NAME;
    if (argc >= 2) {
        ppm_filename = argv[1];
    }
    // ppm_buffer buffer = generate_fake_data();
    const vec3d camera = {
        0.0,
        0.0,
        0.0,
    };
    ppm_buffer buffer = generate_gradient_data_from(&camera);
    ppm_to_file(buffer, ppm_filename);
    free(buffer);
    return 0;
}
